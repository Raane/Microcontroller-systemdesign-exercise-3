/*****************************************************************************
 *
 * Øving 3 uCSysDes, buttonkoden
 *
 *****************************************************************************/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/slab.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/ioport.h>
#include <asm/io.h>
#include <asm/uaccess.h>

#include "ap7000.h"

/* prototypes */
static int __init button_init(void);
static void __exit button_exit(void);
static int button_open (struct inode *inode, struct file *filp);
static int button_release (struct inode *inode, struct file *filp);
static ssize_t button_read (struct file *filp, char __user *buff,
        size_t count, loff_t *offp);
static ssize_t button_write (struct file *filp, const char __user *buff,
        size_t count, loff_t *offp);
/* fops-struct */

static struct file_operations button_fops = {
    .owner = THIS_MODULE,
    .read = button_read,
    .write = button_write,
    .open = button_open,
    .release = button_release
};

int button_major=151;
volatile avr32_pio_t *piob = &AVR32_PIOB;
char *button_state;

/*****************************************************************************/
/* init-function (called when a module loads) */

static int __init button_init (void) {
    int result;
    /* allocate device-number */

    /* asks for access to I/O-ports */
    request_region(AVR32_PIOB_ADDRESS, 102400, "buttons");

    /* initialising PIO-hardware (as in ex. 2) */
    piob->per |= 0xFF;
    piob->puer |= 0xFF;
    piob->ier |= 0xFF;

    
    /*Allocating memory to button state*/
    button_state = kmalloc(1, GFP_KERNEL); 
    if(!button_state){
        printk("<1>kmalloc failed!\n");
    }
    memset(button_state, 0, 1);



    /* Regisering the device in the system (Must be done after everything is initialised) */
    printk("<1> Button driver is initing\n");
    result = register_chrdev(button_major, "button", &button_fops);
    if (result < 0) {
        printk(
                "<1>memory: cannot obtain major number %c\n",button_major);
        return result;
    }
}

/*****************************************************************************/
/* Exit-function (called when the module is removed from the system) */

static void __exit button_exit (void) {
    
    kfree(button_state);
    release_region(AVR32_PIOB_ADDRESS,102400);
    printk("<1> Buttons driver exiting\n");
    unregister_chrdev(button_major, "button");
}

/*****************************************************************************/
/* fops-funkctions */

static int button_open (struct inode *inode, struct file *filp) {
    return 0;
}

/*---------------------------------------------------------------------------*/

static int button_release (struct inode *inode, struct file *filp) {
    return 0;
}

/*---------------------------------------------------------------------------*/

static ssize_t button_read (struct file *filp, char __user *buff,
        size_t count, loff_t *offp) {
    /*Alocate a byte to store the buttonstate*/ 
    int raw_read;
    *button_state = 0;   

    /*Reading the current button state*/
    raw_read = ~(piob->pdsr);
    if(raw_read&0x100) {
        *button_state += 0x1;
    }if(raw_read&0x200) {
        *button_state += 0x2;
    }if(raw_read&0x400) {
        *button_state += 0x4;
    }if(raw_read&0x2000) {
        *button_state += 0x8;
    }if(raw_read&0x4000) {
        *button_state += 0x10;
    }if(raw_read&0x8000) {
        *button_state += 0x20;
    }if(raw_read&0x10000) {
        *button_state += 0x40;
    }if(raw_read&0x40000000) {
        *button_state += 0x80;
    }
    
    /* Debounce */
    int i = 1000;
    while(i>0) i=i-1;

    /* Transfering data to user space */
    copy_to_user(buff,button_state,1);
   
    /* Changing reading position as best suits */ 
    if (*offp== 0) { 
        *offp+=1; 
        return 1; 
    } else { 
        return 0; 
    }
}

/*---------------------------------------------------------------------------*/

static ssize_t button_write (struct file *filp, const char __user *buff,
        size_t count, loff_t *offp) {
    /*One doesn't simply write to a button*/
    printk("<1> Tried to write to a button\n");
    return 1;
}

/*****************************************************************************/
/* module description macros */
module_init (button_init);
module_exit (button_exit);

MODULE_LICENSE ("GPL");
MODULE_DESCRIPTION ("Driver for the leds of a avr32 running on a stk1000");
MODULE_VERSION ("1.0");
MODULE_AUTHOR ("Rune Holmgren and Sigve Sebastian");
