# xyann00_daily

Lily58/rev1 layout for everyday writing in English and Windows Czech QWERTY.
The older `xyann00_shift` keymap is unchanged and remains a separate build target.

## Main changes

| Position | Old | New |
| --- | --- | --- |
| Left edge beside Z | Left Ctrl | Dedicated left Shift |
| Right edge beside / | Right Ctrl | Dedicated right Shift |
| Left edge beside A | Left Shift | Dedicated left Ctrl |
| Right edge beside semicolon | Quote / Shift | Quote; Shift gives double quote |
| Right thumb, former Delete | Delete | Dedicated right Ctrl |
| Left thumb, former LOWER | Symbols | L-NAV: left navigation, right symbols |
| Right thumb, former RAISE | Navigation / keypad | R-NAV: right navigation, left numbers/symbols |
| Left inner key | Previous desktop | Previous desktop on every layer |
| Right inner key | Next desktop | Next desktop on every layer |

Every modifier has one job. There are no Mod-Taps, Layer-Taps, timing windows,
Chordal Hold settings, or letter-specific exceptions. Space, Enter, Tab,
Backspace, both Alt keys and the Windows key remain in their familiar positions.

## Base layout

US mode (unshifted legends):

```text
 Esc    1    2    3    4    5                 6    7    8    9    0    =
 Tab    Q    W    E    R    T                 Y    U    I    O    P   Bksp
 Ctrl   A    S    D    F    G                 H    J    K    L    ;    '
 Shift  Z    X    C    V    B   PrevDS NextDS N    M    ,    .    /   Shift
                  Win  Alt L-NAV Space   Enter R-NAV Ctrl AltGr
```

CZ mode keeps the same letters, modifiers and thumbs. The native Czech top row
is `+`, e-caron, s-caron, c-caron, r-caron, z-caron, y-acute, a-acute,
i-acute, e-acute, dead acute. The semicolon position gives u-ring;
R-NAV + quote gives u-acute. The slash position gives minus. Comma and period keep
the native Czech shifted characters (question mark and colon).

The right home-row quote key gives apostrophe directly in both modes, and
Shift+quote gives double quote. Ctrl/Alt/Windows combinations with that key
retain the underlying physical keycode instead of the Czech quote override.

## English / Czech modes

Windows and QMK must agree about the active layout:

1. Select **English (United States), US** or **Czech (QWERTY)** in Windows.
2. Hold **both layer thumb keys**, then tap **U** for US or **C** for CZ.
3. Release both layer keys before typing.

The keyboard remembers the selection through unplugging. A fresh EEPROM starts
in US mode. Mode selection changes only QMK, not the Windows input language;
ordinary USB keyboard reports do not tell QMK the host's current language.
If you keep Windows on Czech QWERTY, leave QMK in CZ and write English there too.
This layout does not require changing any Windows language settings.

The Czech mappings target Windows KLID **00010405**, not Czech QWERTZ or a Mac
layout. QMK's generic `keymap_czech.h` has different AltGr symbol positions, so
this keymap has a small, explicit `keymap_czech_qwerty.h` instead.

## Czech typing

- Common accents are on the top row, u-ring beside L, and u-acute on R-NAV + quote.
- Top-right is the dead acute key; Shift+top-right is the dead caron key.
- For an uppercase accented letter, press the appropriate dead accent, release
  it, then Shift+letter. For example, Shift+dead-accent, release, then Shift+C
  produces capital C with caron. Caps Lock is also available on SETTINGS+Tab.
- Hold R-NAV for the left-hand number pad and digits 1-5; L-NAV gives digits 6-0.
- These digits use keypad codes in both language modes; enable Num Lock with
  both layer thumbs + N. The base top row retains its normal US/CZ behavior.
- L-NAV has `=` on the right at the same positions in both modes, using the
  correct host-specific code. It does not use unreliable keypad-equals.
- AltGr stays on the right outer thumb for native Czech symbols. For example,
  AltGr+2 gives @ in Windows Czech QWERTY.
- Both inner keys switch Windows desktops in either language; backslash and
  pipe remain available on L-NAV.

## Navigation and window switching

Each thumb enables navigation on its own half and numbers/symbols on the other.
Hold **L-NAV** (left thumb):

- Left arrows: **E** up, **S** left, **D** down, **F** right.
- W/R = End/Home; T/G = Page Up/Down.
- Q = terminal shortcut (`KY_TERM`, Ctrl+F13), identical in US/CZ modes.
  The terminal application must have Ctrl+F13 assigned; firmware sends the shortcut.
- A = clipboard history (`KY_WPST`, Win+V).
- Tab = the restored held-Ctrl tab switcher from `xyann00_shift` (see below).
- Z/X/C/V = Undo/Cut/Copy/Paste; B = Delete, replacing the former Redo macro.
  Redo remains available as ordinary Ctrl+Y on the base layer.
- Top row 1 through 5 = F1 through F5.
- Right half = symbols; right AltGr thumb = Menu (`KC_APP`).
  Menu deliberately stays opposite the held left thumb, not on R-NAV.
  It opens the focused item's context menu.
  This is the keyboard Menu key, not a mouse click at the pointer position.

Hold **R-NAV** (right thumb):

- Right arrows: **I** up, **J** left, **K** down, **L** right.
- U/O = Home/End; Y/H = Page Up/Down.
- P = right Ctrl, allowing Ctrl+arrows without holding two right thumb keys.
  Both dedicated base Ctrl keys remain unchanged; release P before leaving R-NAV.
- Semicolon position = Delete; top-right equals/acute position = Insert.
- Backspace remains Backspace; quote = u-acute in CZ, `[` in US.
- Top row 6 through 0 = F6 through F10; N/M = F11/F12.
- Left half = number pad and symbols; right AltGr remains AltGr.

On either navigation half, Ctrl enables word navigation and Shift selects text.
Both inner keys switch Windows desktops on every layer including base.
Additional held modifiers still affect these shortcuts.

For **left-hand-only Ctrl+Tab**:

1. Hold the left layer thumb (L-NAV), then press Tab.
2. Ctrl stays held while L-NAV remains held. Tap Tab again to keep cycling;
   hold Shift while pressing Tab to cycle backwards.
3. Release L-NAV to release the generated Ctrl. A physically held left or right
   Ctrl remains held independently. Either Tab/thumb release order is supported.

Merely holding L-NAV does not press Ctrl; the first Tab starts the latch.
Until L-NAV is released, other keys also receive the held Ctrl, as in the old
keymap. Both layer thumbs + Tab remains Caps Lock on SETTINGS.

For **left-hand-only Alt+Tab**:

1. Hold the normal **left Alt thumb key**.
2. Tap Tab to open/cycle the switcher and activate its arrow layer.
3. Use E/S/D/F to select a window. Shift+Tab cycles backwards; Escape cancels.
4. Release Alt to accept the selection and return to the previous layer.

The switcher also uses the original right-hand I/J/K/L arrow positions
and the same Home/End positions as the mixed layers. Terminal/clipboard shortcuts are not
enabled on this temporary layer while Alt is held.

Alt stays an ordinary modifier until Tab is pressed: Alt+F4 and other Alt
shortcuts keep working. Right Alt/AltGr never activates the switcher. Releasing
left Alt or pressing Escape removes the temporary layer. There is no tap/hold
timing or artificial modifier latch, and no inner key needs to be held.

## Mac compatibility

The keyboard remains a standard USB keyboard and can type on a Mac. The US mode
works with a matching US input source; the Windows-logo key acts as Command and
Alt acts as Option. The current Windows Czech quote/symbol mappings should not
be assumed to match a macOS Czech input source.

The special switcher and editing macros are currently for Windows. A Mac profile
would need Command+Tab and Command-based editing shortcuts, plus verified Czech
mappings for the selected Mac input source. The keyboard Menu key also has no
guaranteed equivalent context-menu binding on macOS. No Mac profile is included
or claimed tested in this keymap.

## Numbers, symbols and settings

The symbol positions are unchanged, but are reached with the opposite thumb:
hold **R-NAV** for the left half below, or **L-NAV** for the right half.

```text
        1    2    3    4    5                 6    7    8    9    0    =
        `    ~    7    8    9                 \    |    [    ]    +
        !    @    4    5    6                 *    :    (    )    =    "
        #    0    1    2    3   PrevDS NextDS  ^    _    {    }    -
```

The diagram shows the two symbol halves, not a single layer. Both layer keys
together activate SETTINGS, not a combined number/symbol layer.

Both Ctrl/Shift base keys are preserved. Every digit shown above uses a keypad
keycode (`KC_P0` through `KC_P9`), identical in US and CZ modes. With Num Lock on,
the keypad produces digits in either Windows input layout without a synthetic
Shift modifier. With Num Lock off, the OS can interpret these keys as keypad
navigation/editing keys instead; keypad 5 may do nothing. Held Shift can also
alter keypad behavior on Windows.

Toggle Num Lock with **both layer thumbs + N**. This changes the host's Num Lock
state, including for other connected keyboards; firmware does not force it on.
Applications can distinguish keypad digits from top-row digits, so use the base
physical number row for shortcuts that specifically require top-row keys.
Symbols, including equals, still use the matching US/CZ mappings and are not
converted to keypad operators or keypad-equals. Extra physical modifiers still
affect symbols, as on a normal keyboard.

Hold **L-NAV + R-NAV** for SETTINGS: A mute, S volume down, D volume up, F play/pause,
M previous track, comma next track, Tab Caps Lock, N Num Lock, O OLED on/off,
U US mode, C CZ mode. RGB remains disabled.

## OLED status

Only the USB-connected half displays status; the other OLED stays off.
The display shows exactly two fields: `Keyboard: US` or `Keyboard: CZ`, and
`Num Lock: ON` or `Num Lock: OFF`. Active layers are not displayed.

- The mode is QMK's saved US/CZ mode, not a detection of Windows' input layout.
  Change it with both layer thumbs + U/C. Win+Space still changes Windows only.
- Num Lock comes from the host's keyboard LED report, not a local guess.
- Both layer thumbs + O toggles the status display. The toggle is not saved
  to EEPROM; reconnecting or restarting the keyboard enables it again.
- The display sleeps after 60 seconds without keyboard or host lock-state
  activity and wakes on activity, unless manually disabled. Brightness is 128/255.
- Both halves use the same firmware; display orientation follows physical
  handedness, while only the USB-connected half renders the status.

## Build and flash

Run in QMK MSYS:

```sh
qmk compile -kb lily58/rev1 -km xyann00_daily
qmk flash -kb lily58/rev1 -km xyann00_daily
```

Double-press the controller's reset button when the flasher is waiting. Flash
both halves with this keymap; retain the existing EEPROM handedness. Do not erase
EEPROM or add a different controller converter for this existing Pro Micro build.
Firmware: `C:/qmk/qmk_userspace/lily58_rev1_xyann00_daily.hex`.

To return to the previous layout, flash `xyann00_shift`. Before reverting, select
US mode in the new keymap so its saved default layer is 0, the old keymap's base.
If already reverted while saved in CZ mode, reflashing daily and selecting US
restores that setting without erasing handedness.

## Local checkout and validation

- Personal GitHub repository: https://github.com/xYann00/qmk_userspace
- Active local userspace: `C:/qmk/qmk_userspace`.
- QMK firmware: `C:/Users/Jan Demel/Documents/github/qmk_firmware`.
- QMK config: `user.overlay_dir` points to the first path; `user.qmk_home` to the second.
- The old Documents userspace copy was removed earlier; these two current
  directories have different roles and are not mirrored copies.
- Firmware updated from `c638100030` to upstream `08c662f286` (tag `0.34.4`).
- QMK MSYS packages updated on 2026-09-17; CLI 1.2.0, Python 3.14.7.
- AVR/ARM compiler toolchains already match the latest release, v15.2.0-1.
- Flashing utilities updated to release 20260711, avrdude 8.1-20260701.
- `qmk doctor` passed after the firmware/MSYS update.
- The initial `xyann00_daily` version compiled successfully; see revision checks below.
- `qmk userspace-compile --print-failures` passed for both `xyann00_daily` and
  the unchanged `xyann00_shift` on the updated firmware source.

All 44 Czech character definitions were compiled using QMK's headers and checked
using Windows `ToUnicodeEx` with layout 00010405, including quote, equals,
brackets, accents and nested Shift+AltGr symbols. The visual guide was checked at
736px and 320px for all layers and both languages, including the shifted base.

### Alt+Tab / Menu revision

- Revised firmware compiled on 2026-09-17: 15,930 of 28,672 bytes flash (55%).
- The actual switcher callback passed isolated C logic tests for ordinary Tab,
  Ctrl+Tab, AltGr, other Alt shortcuts, Alt+Tab/Shift+Tab entry, both Tab/Alt
  release orders, Escape, and preservation of underlying layers/modifiers.
- Menu is `NAV + right AltGr`; the right AltGr base key remains `KC_RALT`.
- The revised visual was checked for both modes and all layers at 736px/320px.
- These checks do not simulate the host switcher or replace physical testing.

### NAV / desktop revision

- Revised firmware compiled on 2026-09-24: 15,930 of 28,672 bytes flash (55%).
- QMK's exported keymap passed position checks for all seven 58-key layers,
  desktop keys, terminal/clipboard, F11/F12, Menu, and matching switcher arrows.
- The revised visual passed checks at 736px/320px for both modes and all layers,
  including shifted base labels, with no text overflow or JavaScript errors.
- The original `xyann00_shift` keymap remains unchanged. No firmware was flashed.

### Mixed navigation / symbols revision

- Compiled on 2026-09-24: 16,056 of 28,672 bytes flash (55%).
- Both mixed layers have US/CZ variants; base mode indices 0/1 are unchanged.
- QMK's exported keymap passed checks for all eight 58-key layers, Menu on
  L-NAV + right AltGr, ordinary AltGr on R-NAV, Delete, Ctrl and function keys.
- The actual layer-state callback passed isolated C tests over 512 input states,
  including stale overlay cleanup, idempotence and both thumb release orders.
- The revised visual passed both modes and all views at 736px/320px without
  label overflow or JavaScript errors. The old keymap remains unchanged.
- No firmware was flashed; test physical chords before adopting this revision.

### Keypad digits revision

- Compiled on 2026-09-24: 16,056 of 28,672 bytes flash (55%), unchanged in size.
- All 40 digit mappings across the US/CZ mixed layers now use keypad keycodes.
- SETTINGS + N toggles Num Lock. A before/after export comparison confirmed
  that these 41 positions changed and all other 423 positions stayed unchanged.
- The visual passed both modes and all layers at 736px/320px, including the
  Num Lock position and keypad tooltips. The original keymap remains unchanged.
- No firmware was flashed or physical Num Lock behavior tested on the keyboard.

### OLED status revision

- Compiled on 2026-09-24: 19,676 of 28,672 bytes flash (68%).
- Static RAM usage is 1,114 bytes (.data + .bss), leaving 1,446 bytes for
  stack/runtime use on the ATmega32U4; this is not a measured stack high-water mark.
- The actual OLED callbacks passed isolated C tests for US/CZ, Num Lock,
  text bounds, toggle press/release, idle sleep, wake, and both display rotations.
- Tests also verified that disabled/secondary displays remain off after a
  simulated driver render, and that the existing Alt+Tab callback still works.
- The key array changed only at SETTINGS + O; the mixed-layer callback and
  original `xyann00_shift` keymap are unchanged.
- The guide passed both modes and all layers at 736px/320px, including the
  OLED toggle position. Physical OLED operation/orientation still needs testing.
- No firmware was flashed and no Win+Space mode synchronization was added.

### Terminal / Ctrl+Tab revision

- Compiled on 2026-09-24: 19,774 of 28,672 bytes flash (68%).
- L-NAV + Q now sends Ctrl+F13 in both modes. Configure the target terminal
  application to use that shortcut; the firmware does not change app settings.
- L-NAV + Tab restores the old held-Ctrl tab switcher, with independent tracking
  of a physically held left Ctrl. Right Ctrl remains handled normally by QMK.
- The actual callbacks passed isolated C tests in US/CZ for repeated Tab,
  Shift+Tab, both Tab/thumb release orders, physical Ctrl before/during the
  latch, settings/mode transitions, ordinary Tab/Alt+Tab/AltGr, and OLED toggle.
- Only the left-layer terminal/Tab key assignments changed; OLED rendering
  and the original `xyann00_shift` keymap are unchanged.
- The guide passed both modes and all views at 736px/320px. No firmware flashed.

Compilation checks do not replace typing on the keyboard: test `don't`, `:D`,
both Ctrl keys, Ctrl+Shift+T, Czech accents, mode switching, Menu, and Alt+Tab with
arrows (including releasing Alt before an arrow) before adopting this layout as
your daily firmware. Also check terminal/clipboard shortcuts, desktop switching,
the moved F11/F12 keys, and R-NAV + quote for Czech u-acute. Check keypad digits
in both Windows input layouts with Num Lock on, off, and with Shift held.
After flashing both halves, check the two status fields, both-thumbs + O,
idle sleep/wake and the inactive half's display remaining off.
Test Ctrl+F13 in the terminal and L-NAV + Tab/Shift+Tab in your browser or editor,
including releasing the layer thumb before Tab and while physical Ctrl is held.

Sources: [QMK key overrides](https://docs.qmk.fm/features/key_overrides),
[Windows Czech QWERTY](https://learn.microsoft.com/en-us/globalization/keyboards/kbdcz1).
