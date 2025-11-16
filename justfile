compile:
    qmk flash -kb splitkb/aurora/sweep/rev1 -km gameflave

clear-eeprom:
    qmk flash -kb splitkb/aurora/sweep/rev1 -km gameflave -e EEPROM_CLEAR=yes
