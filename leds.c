/****************************************************************************
 *
 * Øving 3 uCSysDes, ledkoden
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

static int __init led_init(void);
static void __exit led_exit(void);
static int led_open (struct inode *inode, struct file *filp);
static int led_release (struct inode *inode, struct file *filp);
static ssize_t led_read (struct file *filp, char __user *buff,
        size_t count, loff_t *offp);
static ssize_t led_write (struct file *filp, const char __user *buff,
        size_t count, loff_t *offp);
static void set_leds(char leds);
/* fops-struct */

static struct file_operations led_fops = {
    .owner = THIS_MODULE,
    .read = led_read,
    .write = led_write,
    .open = led_open,
    .release = led_release
};

int led_major=150;
volatile avr32_pio_t *piob = &AVR32_PIOB;
char *led_status;


/*****************************************************************************/
/* init-function (called when the module is loading) */

static int __init led_init (void) {
    int result;
    /* alocating device-number */

    /* asks for access to I/O-ports */
    request_region(AVR32_PIOB_ADDRESS, 102400, "leds");

    /* initialising PIO-hardware (as in ex. 2) */

    piob->per = 0xFF;
    piob->oer = 0xFF;
      led_status= kmalloc(1, GFP_KERNEL); 
      if(!led_status){
          printk("<1>kmalloc failed!\n");
      }
       memset(led_status, 0, 1);


    /* Regisering the device in the system (Must be done after everything is initialised) */
    printk("<1>Led driver is initing\n");
    result = register_chrdev(led_major, "led", &led_fops);
    if (result < 0) {
        printk("<1>memory: cannot obtain major number %d\n",led_major);
        return result;
    }

    /* Turn off all leds */
    //it's faster to use piob->codr = 0xFF, but this code is cleaner 
    set_leds(0x00); 
}

/*****************************************************************************/
/* Exit-function (called when the module is removed from the system) */

static void __exit led_exit (void) {

    /*Turn off the lights*/
    set_leds(0x00);
    kfree(led_status);
    release_region(AVR32_PIOB_ADDRESS,102400);
    printk("<1> Led driver is exiting\n");
    unregister_chrdev(led_major, "led");
}

/*****************************************************************************/
/* fops-function */

static int led_open (struct inode *inode, struct file *filp) {
    return 0;
}

/*---------------------------------------------------------------------------*/

static int led_release (struct inode *inode, struct file *filp) {
    return 0;
}

/*---------------------------------------------------------------------------*/

static ssize_t led_read (struct file *filp, char __user *buff,
        size_t count, loff_t *offp) {
    /* Transfering data to user space */ 
    copy_to_user(buff,led_status,1);

    /* Changing reading position as best suits */ 
    if (*offp== 0) { 
        *offp+=1; 
        return 1; 
    } else { 
        return 0; 
    }
}

/*---------------------------------------------------------------------------*/

static ssize_t led_write (struct file *filp, const char __user *buff,
        size_t count, loff_t *offp) {
    copy_from_user(led_status, buff+count-1, 1);  
    /* printk("<1> writing new led_status:%d ", *led_status); */
    set_leds(*led_status);

    return 1;
}

static void set_leds(char leds) {
    piob->codr = 0xFF;
    piob->sodr = leds;
}

/*****************************************************************************/
/* module description macros */

module_init (led_init);
module_exit (led_exit);

MODULE_LICENSE ("GPL");
MODULE_DESCRIPTION ("Driver for the leds of a avr32 running on a stk1000");
MODULE_VERSION ("1.0");
MODULE_AUTHOR ("Rune Holmgren and Sigve Sebastian");

