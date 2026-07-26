/*

 ZEB-RGBD stands for "Zebronics RGB Daemon"

 zeb-rgbd - A tiny daemon for keyboards that use the Scroll Lock LED
 to control RGB lighting.

 Author: Guru Prasad Mishra

 why does this exist ?
   On my Fedora 44 + Hyprland (Wayland) setup, my Zebronics keyboard's
   RGB lighting is controlled by the Scroll Lock LED state.
   Under Wayland, the "xset" utility cannot be used and the Linux Kernel
   resets the Scroll Lock LED to OFF whenever another key is pressed.

   This daemon watches the Scroll Lock LED and restores it to ON whenever
   the kernel turns it OFF, keeping the keyboard RGB enabled.
   
   Yes... all of this just to keep my keyboard glowing. :)
   Hehe , alright bye bye :) 

*/

// Required headerfiles
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/inotify.h>
#include<string.h>

#define LED_FILE "/sys/class/leds/input3::scrolllock/brightness"

static void force_on(void)
{
   FILE *fp = fopen(LED_FILE,"w");
   if(!fp)
   {
      return;
   }  
   fputs("1\n", fp);
   fclose(fp);
}

int main(void)
{
   int fd;
   int wd;
   char buffer[4096];
   printf("zeb-rgbd started...\n");
    
   force_on();             
   fd = inotify_init1(0);

 if (fd < 0)
   {
   perror("inotify");
   return 1;
   }

 wd = inotify_add_watch(fd,LED_FILE,IN_MODIFY);
    
 if (wd < 0)
 {
   perror("watch");
   return 1;
 }

   while (1)
   {
   read(fd, buffer, sizeof(buffer));
   force_on();
   }

 return 0;

}    



