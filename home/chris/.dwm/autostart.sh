bkg_img=/usr/share/backgrounds/color_crystal.jpg

picom -D 6 &                # transparency support
wal -n -i "${bkg_img}"      # colorscheme
nitrogen --set-scaled --head=0 "${bkg_img}"
nitrogen --set-scaled --head=1 "${bkg_img}"
#nitrogen --restore &        # wallpaper
#xrdb merge ~/.Xresources &  # X11 theming
slstatus &                  # status bar
blueman-applet &            # bluetooth
dunst &                     # notifications
