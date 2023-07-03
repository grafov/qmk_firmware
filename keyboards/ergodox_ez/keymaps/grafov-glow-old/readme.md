My keymap for Ergodox EZ
========================

This weird layout may be used probably by only one person on this
planet - by me. But some tricks could be useful for other users of
Ergodox EZ. See some examples below. For clarity letter placed keys
referenced to their QWERTY counterparts. I think after using Ergodox
awhile I will backport changes to general Keymacs.

The current layout is:

    ,--------------------------------------------------.           ,--------------------------------------------------.
    |   Esc  |   `  |   :  |   -  |   !  |   +  | DEL  |           | NumLk|   *  |   ?  |   "  |   ;  |   =  |   BSP  |
    |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    |   Alt  |   q  |   b  |   p  |   f  |   g  |  Fn  |           |  Fn  |   v  |   w  |   l  |   y  |   '  |   Alt  |
    |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    |   Ctl  |   r  |   a  |   e  |.  n  |   s  |------|           |------|   d  |.  o  |   t  |   i  |   h  |   Ctl  |
    |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    |  Shift |   z  |   ,  |   u  |   k  |   j  |      |           |      |   m  |   c  |   x  |   .  |   /  |  Shift |
    `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
      | LAT  |  LAT |      |   _  |      |                                       |      |      |      |  RUS |  RUS |
      `----------------------------------'                                       `----------------------------------'
                                           ,-------------.       ,-------------.
                                           |      | Back |       | Frwd | CtlW |
                                    ,------|------|------|       |------+------+------.
                                    |      |      | CtlV |       | CtlR |      |      |
                                    |  SPC |  Tab |------|       |------| Ret  | SPC  |
                                    |      |      | CtlC |       | Ins  |      |      |
                                    `--------------------'       `--------------------'


Moved control keys
------------------

Large keys on the left and on the right sides of the keyboard have
used for Alt, Ctl, Shift (as mentioned here from top to
down). CapsLock and other historical keys moved away.

Additional control keys on hold
-------------------------------

I found it is very comfortable to add even more control keys to the
each side of the keyboard. So on the left I have set:

* T -> RALT_T()
* G -> RCTL_T()
* B -> SFT_T()

And symmetrically on the right:

* Y -> LALT_T()
* H -> LCTL_T()
* N -> SFT_T()

So I can use control combos not only with pinkys but additionally by
index fingers and thumbs. Not for even combos of course. But for
example hold the B or N by thumb is good alternative for CapsLock mode
for me.

See the first two layers in the keymap for this feature.

Backlite colors
---------------

On each layer change backlite set its own color. Additionally I set
RGB LEDs. Firstly I had used only LEDs but their not good visible when
you are concentrated on the screen. Backlit colors are bright and good
visible by the lateral vision. See `void matrix_scan_user(void)`.

Keymacs layout
--------------

I had used Keymacs on general keyboards for a while and finally
adapted it for Ergodox. I still think even with good hardware the
placement of the letters is important for ergonomics. So the layouts
like Workman or Colemak even Dvorak is safer for your fingers then
default Qwerty.

See more info about Emacs oriented layout:
https://github.com/keyboard-ergonomics/keymacs

Russian layout
--------------

Ergodox has one less column than common keyboards so some Russian
letters had lost their place and I placed them on my own taste.

* Э (ae letter) moved to dot key position.
* Х (khe letter) moved to top for the right index finger.

Tap-dance tricks:

* press once for Ь (soft sign) and twice for Ъ (hard sign)

It is obviously useful for any keyboards with Russian layout because
hard sign moved to different positions in different layouts and wastes
one key for self or shifted. I found tap-dance feature for this case
more comfortable than usage of Shift. These two letters Ь and Ъ are
similar in usage and there are no any valid word in Russian where they
are doubled.

The similar situation has place with Е and Ё letters. But tap-dance
may follow some troubles here because there are some words (rare used
though) where Е letter doubled or even tripled (word "длинношеее" for
example). So I still thinking about placing poor Ё on the keyboard.

I had used custom made
solution [shift-shift](https://github.com/grafov/shift-shift) but
with Ergodox I have switched to default `xkb`. The lowest key in the
right corner of the right part have using for RUS layout and the
lowest key in the left corner of the left part for the LAT. I put the
help string with `xkb` settings as keyboard macro. See the usage of:

   #define XKBSTR "setxkbmap -layout \"us,ru(typewriter)\" -option grp:sclk_toggle -option lv3:caps_switch -option misc:typo"

in the code.

## Common punctuations

For both Latin and Russian layers I have tried to map punctuations to the same places. So the dot and comma in the Russian layout have the same places as in the Keymacs. It was required to move two more keys in the Russian layout to unusual places. 

* Dot in the Russian had used the place of `Ч`, so `Ч` have moved to the upper row, where `:` placed in the Keymacs.
* Comma in the Russian had used the place of `Ю`, so `Ю` have moved to the upper row, where `;` placed in the Keymacs.
