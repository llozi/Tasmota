esptool.py --chip esp32 --baud 2000000 --before default_reset --after hard_reset write_flash -z --flash_mode dio --flash_freq 80m --flash_size detect 0x1000 bootloader_qio_80m.bin 0x8000 partitions_spiffs_12M.bin 0xe000 boot_app0.bin 0x10000 tasmota32-odroid.bin
