# 1upkeyboards/1up60hse:ahhsumx

Custom keymap utilizing 3 layers for 1upkeyboards' 60% Hot Swap Edition PCB. Main use of this layout is for programming.

## keyboard layout

Each # indicates the units size of that key. This keyboard a pretty standard 60% layout.

Pretty sure this is right, hah.

```
  // -----------------------------------------------------------------------------------------------------
  // |  1   |   1  |   1  |   1  |   1  |   1  |   1  |   1  |   1  |   1  |   1  |   1  |   1  |    2   |
  // -----------------------------------------------------------------------------------------------------
  // | 1.25   |  1   |  1   |  1   |  1   |  1   |  1   |  1   |  1   |  1   |  1   |  1   |  1   | 1.25 |
  // -----------------------------------------------------------------------------------------------------
  // | 2        |  1   |  1   |  1   |  1   |  1   |  1   |  1   |  1   |  1   |  1   |  1   |     2.25  |
  // -----------------------------------------------------------------------------------------------------
  // | 2.25       |  1   |  1   |  1   |  1   |  1   |  1   |  1   |  1   |  1   |  1   |     2.75       |
  // -----------------------------------------------------------------------------------------------------
  // | 1.5    |  1.5   |  1.5    |                6.25               |  1.5   |  1.5   | 1.5    | 1.5    |
  // -----------------------------------------------------------------------------------------------------
```

## Layers

General key across all layers:
- `xxxx` means the key is not used on that layer
- `____` means the key is "transparent" and falls through the whatever that key does on the layer below it
- all other keys are standard, or explained in the section about the layer

1. BASE

This layer is the default layer. It uses a mostly standard QWERTY layout, with a few alterations.

- GESC: Grave Escape is a key that doubles as ESCAPE and GRAVE `\``. When pressed alone, it acts like escape. When pressed along with a command key, it acts as grave, add shift to get tilde. It may take a little getting used to, but it is a handy 2 for 1 key.
- BASEALT: This key engages the `BASE ALT` layer while held down. Think of it like a command key, but the layer is fairly unique and explained below.
- CAPS: This is a standard caps lock key, but it is not in a standard place. I find it much less useful than having access to another layer, so it has been de-prioritized.
- ONESHOT MACRO: This key enables the `LAYER MACRO` layer when pressed. It does not need held, as it acts as a oneshot key (explained further in the LAYER MACRO section).
- BASEALT/ENTER dups: The bottom right two keys are dup's of the other keys of the same name. They are just secondary positions that are sometimes more easy to use.

```
  // -----------------------------------------------------------------------------------------------------
  // | GESC |  1!  |  2@  |  3#  |  4$  |  5%  |  6^  |  7&  |  8*  |  9(  |  0)  |  -_  |  =+  |  BSPC  |
  // -----------------------------------------------------------------------------------------------------
  // | TAB    |  Q   |  W   |  E   |  R   |  T   |  Y   |  U   |  I   |  O   |  P   |  [{  |  ]}  |  \|  |
  // -----------------------------------------------------------------------------------------------------
  // | BASEALT  |  A   |  S   |  D   |  F   |  G   |  H   |  J   |  K   |  L   |  ;:  |  '"  |    ENTER  |
  // -----------------------------------------------------------------------------------------------------
  // | LSHIFT     |  Z   |  X   |  C   |  V   |  B   |  N   |  M   |  ,>  |  .>  |  /?  | ONESHOT MACRO  |
  // -----------------------------------------------------------------------------------------------------
  // | LCTRL  |  LALT  |  LGUI   |                SPACE              |  RALT  |  CAPS  | BASEALT| ENTER  |
  // -----------------------------------------------------------------------------------------------------
```

2. BASE ALT

This layer is toggled when one of the `BASEALT` keys on the BASE layer is held down. This layer gives access to some of the less used keys that are physically absent from 60% boards, along with access to some shortcuts that are uncomfortable to press.

- top row: regular escape, F1-12, and a command+escape shortcut
- LG+_: these keys all give access to `command + __somekey__` combos. I find them naturally more comfortable, and they all map to the physical key that would be in the same place so they are easy to recall.
- arrow keys: at the location of `i` `k` `j` and `l` are access to `up` `down` `left` and `right` arrow keys
- at the bracket keys (`[` and `]`) the shortcuts may not look instantly familiar, these are `previous tab` and `next tab` in most applications.
- underneath the quote key is access to grave `\`` which is sometimes more comfortable than using grave escape.
- underneath comma, and period, are macro keys for vim previous tab, and next tab.
- the space bar becomes an underscore, very useful for coding once you get used to it.

```
  // -----------------------------------------------------------------------------------------------------
  // | ESC   |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |LG+BSPC |
  // -----------------------------------------------------------------------------------------------------
  // | ______ | LG+Q | LG+W | LG+E | LG+R | LG+T | xxxx | xxxx |  UP  | xxxx | xxxx | LG+{ | LG+} | ____ |
  // -----------------------------------------------------------------------------------------------------
  // | ______   | LG+A | LG+S | LG+D | LG+F | LG+G | ____ | LEFT | DOWN | RIGHT| ____ |  `~  |    ______ |
  // -----------------------------------------------------------------------------------------------------
  // | ______     | LG+Z | LG+X | LG+C | LG+V | LG+B | xxxx | xxxx | xxxx | :gT  | :gt  |         ______ |
  // -----------------------------------------------------------------------------------------------------
  // | ______ | xxxxxx | _______ |                  _                | xxxxxx | xxxxxx | xxxxxx | xxxxxx
  // -----------------------------------------------------------------------------------------------------
```

3. LAYER MACRO

This last layer is meant to make life easier. Some things get a little bit too repetitive, and it's nice to simplify them. This layer is used as a "one shot layer". This means it is activated by a key, and then once any key on this layer is pressed, the action executes and you return the layer you came from. You must press the one shot key again to perform any subsequent macros from this layer. To exit without performing any macros, you can use `ESCAPE`.

- all vim commands execute immediately (aka they tap `ENTER`)
- `:q`: vim quit
- `:w`: vim write
- `:e`: vim reload
- `dd`: vim delete line
- `:noh`: vim remove highlights
- LG+T: `command+t` - common shortcut to open a new tab
- INSP: `command+alt+i` - opens the inspector in most web browser
- COPY: `command+c` - lazy single key for copy
- PASTE: `command+v` - lazy single key for paste
- LG+N: `command+n` - common shortcut for opening a new window


```
  // -----------------------------------------------------------------------------------------------------
  // | ESC  | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx | xxxxxx |
  // -----------------------------------------------------------------------------------------------------
  // | xxxxxx |  :q  |  :w  |  :e  | xxxx | LG+T | xxxx | xxxx | xxxx | INSP | xxxx | xxxx | xxxx | xxxx |
  // -----------------------------------------------------------------------------------------------------
  // | xxxxxx   | xxxx | xxxx |  dd  | xxxx | xxxx | :noh | xxxx | xxxx | xxxx | xxxx | xxxx |    xxxxxx |
  // -----------------------------------------------------------------------------------------------------
  // | xxxxxx     | xxxx | xxxx | COPY | PASTE| xxxx | LG+N | xxxx | xxxx | xxxx | xxxx |         xxxxxx |
  // -----------------------------------------------------------------------------------------------------
  // | ______ | xxxxxx | _______ |                ______             | ______ | xxxxxx | ______ | ______ |
  // -----------------------------------------------------------------------------------------------------
```

## how to make and flash

1. clone this repo
2. follow all the qmk setup if you haven't
3. `make 1upkeyboards/1up60hse:ahhsumx`
4. open qmk app and load the hex that was generated by that command
5. check the "auto flash" checkbox
6. make sure they keyboard is plugged in :) and press the reset button on the bottom


