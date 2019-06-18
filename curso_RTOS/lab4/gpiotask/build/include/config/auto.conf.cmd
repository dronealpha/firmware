deps_config := \
	/home/diego/esp/esp-idf/components/app_trace/Kconfig \
	/home/diego/esp/esp-idf/components/aws_iot/Kconfig \
	/home/diego/esp/esp-idf/components/bt/Kconfig \
	/home/diego/esp/esp-idf/components/driver/Kconfig \
	/home/diego/esp/esp-idf/components/efuse/Kconfig \
	/home/diego/esp/esp-idf/components/esp32/Kconfig \
	/home/diego/esp/esp-idf/components/esp_adc_cal/Kconfig \
	/home/diego/esp/esp-idf/components/esp_event/Kconfig \
	/home/diego/esp/esp-idf/components/esp_http_client/Kconfig \
	/home/diego/esp/esp-idf/components/esp_http_server/Kconfig \
	/home/diego/esp/esp-idf/components/esp_https_ota/Kconfig \
	/home/diego/esp/esp-idf/components/espcoredump/Kconfig \
	/home/diego/esp/esp-idf/components/ethernet/Kconfig \
	/home/diego/esp/esp-idf/components/fatfs/Kconfig \
	/home/diego/esp/esp-idf/components/freemodbus/Kconfig \
	/home/diego/esp/esp-idf/components/freertos/Kconfig \
	/home/diego/esp/esp-idf/components/heap/Kconfig \
	/home/diego/esp/esp-idf/components/libsodium/Kconfig \
	/home/diego/esp/esp-idf/components/log/Kconfig \
	/home/diego/esp/esp-idf/components/lwip/Kconfig \
	/home/diego/esp/esp-idf/components/mbedtls/Kconfig \
	/home/diego/esp/esp-idf/components/mdns/Kconfig \
	/home/diego/esp/esp-idf/components/mqtt/Kconfig \
	/home/diego/esp/esp-idf/components/nvs_flash/Kconfig \
	/home/diego/esp/esp-idf/components/openssl/Kconfig \
	/home/diego/esp/esp-idf/components/pthread/Kconfig \
	/home/diego/esp/esp-idf/components/spi_flash/Kconfig \
	/home/diego/esp/esp-idf/components/spiffs/Kconfig \
	/home/diego/esp/esp-idf/components/tcpip_adapter/Kconfig \
	/home/diego/esp/esp-idf/components/unity/Kconfig \
	/home/diego/esp/esp-idf/components/vfs/Kconfig \
	/home/diego/esp/esp-idf/components/wear_levelling/Kconfig \
	/home/diego/esp/esp-idf/components/app_update/Kconfig.projbuild \
	/home/diego/esp/esp-idf/components/bootloader/Kconfig.projbuild \
	/home/diego/esp/esp-idf/components/esptool_py/Kconfig.projbuild \
	/home/diego/esp/esp-idf/components/partition_table/Kconfig.projbuild \
	/home/diego/esp/esp-idf/Kconfig

include/config/auto.conf: \
	$(deps_config)

ifneq "$(IDF_TARGET)" "esp32"
include/config/auto.conf: FORCE
endif
ifneq "$(IDF_CMAKE)" "n"
include/config/auto.conf: FORCE
endif

$(deps_config): ;
