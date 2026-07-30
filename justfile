compile:
    qmk flash -kb splitkb/aurora/sweep/rev1 -km flave-dev

clear-eeprom:
    qmk flash -kb splitkb/aurora/sweep/rev1 -km flave-dev -e EEPROM_CLEAR=yes
