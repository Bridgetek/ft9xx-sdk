@rem Populate examples directories with files from a template.
@rem Copes with makefile templates or cmake templates.
@rem Argument 1 is the incoming template file. 
@rem Arguement 2 is a filename to use in all the example directories.
@rem The template file is formatted like example_template.cmake:
@rem A line starting with "# Template" will conditionally turn on or off the next
@rem line of the file. If there is a match with the required keyword in the rest
@rem of the line then the next line will be uncommented and included. There must
@rem be whitespace after the # (comment) in the next line.
@rem After the first pass all template lines and the following line for each
@rem template is removed.
@rem The resulting filtered file is copied to the appropriate examples
@rem directories using the filename supplies in argument 2.
@rem Note: requires GNU utilities for "cat", "awk" to be installed.
@echo off
IF "%1"=="" GOTO :usage
IF "%2"=="" GOTO :usage
GOTO :okargs
:usage
    echo "Usage: ./example_template.bat <template_file> <output_file_name>"
    GOTO :eof
:okargs

rem Create temporary files to store processed files.
set "cm_basic=%tmp%\example_template~%RANDOM%.tmp"
set "cm_fatfs=%tmp%\example_template~%RANDOM%.tmp"
set "cm_freertos=%tmp%\example_template~%RANDOM%.tmp"
set "cm_freertos_lwip=%tmp%\example_template~%RANDOM%.tmp"
set "cm_freertos_d2xx=%tmp%\example_template~%RANDOM%.tmp"
set "cm_d2xxdev=%tmp%\example_template~%RANDOM%.tmp"
set "cm_d2xxhost=%tmp%\example_template~%RANDOM%.tmp"

rem Show the temporary files used.
echo No libraries: %cm_basic%
echo FatFS: %cm_fatfs%
echo FreeRTOS: %cm_freertos%
echo FreeRTOS + lwIP: %cm_freertos_lwip%
echo FreeRTOS + D2XX device: %cm_freertos_d2xx%
echo D2XX device: %cm_d2xxdev%
echo D2XX Host: %cm_d2xxhost%

rem Generate processed files.
cat %1 | awk "/\s*# Template/{getline;next;}1" > %cm_basic%
cat %1 | awk "/^\s*# Template .+(FatFS)/{getline;$1=\"\t\";print;getline;}1" | awk "/\s*# Template/{getline;next;}1" > %cm_fatfs%
cat %1 | awk "/^\s*# Template .+(FreeRTOS)/{getline;$1=\"\t\";print;getline;}1" | awk "/\s*# Template/{getline;next;}1" > %cm_freertos%
cat %1 | awk "/^\s*# Template .+(FreeRTOS|lwIP)/{getline;$1=\"\t\";print;getline;}1" | awk "/\s*# Template/{getline;next;}1" > %cm_freertos_lwip%
cat %1 | awk "/^\s*# Template .+(FreeRTOS|d2xx_dev_rtos |tinyprintf)/{getline;$1=\"\t\";print;getline;}1" | awk "/\s*# Template/{getline;next;}1" > %cm_freertos_d2xx%
cat %1 | awk "/^\s*# Template .+(d2xx_dev )/{getline;$1=\"\t\";print;getline;}1" | awk "/\s*# Template/{getline;next;}1" > %cm_d2xxdev%
cat %1 | awk "/^\s*# Template .+(d2xx_host )/{getline;$1=\"\t\";print;getline;}1" | awk "/\s*# Template/{getline;next;}1" > %cm_d2xxhost%

rem Copy processed files into Examples directories.
copy /y %cm_basic% "ADC Example 1/%2"
copy /y %cm_basic% "ADC Example 2/%2"
copy /y %cm_basic% "ADC Example 3/%2"
copy /y %cm_basic% "ADC Example 4/%2"
copy /y %cm_basic% "ADC Example 5/%2"
copy /y %cm_basic% "BCD Example 1/%2"
copy /y %cm_basic% "Camera Example 1/%2"
copy /y %cm_basic% "CAN Example 1/%2"
copy /y %cm_basic% "CAN Example 2/%2"
copy /y %cm_basic% "CAN Example 3/%2"
copy /y %cm_d2xxdev% "D2XX Example 1/%2"
copy /y %cm_d2xxdev% "D2XX Example UART Bridge/%2"
copy /y %cm_basic% "DAC Example 1/%2"
copy /y %cm_basic% "DAC Example 2/%2"
copy /y %cm_basic% "DAC Example 3/%2"
copy /y %cm_basic% "DLOG Example/%2"
copy /y %cm_basic% "Ethernet Example 1/%2"
copy /y %cm_freertos_d2xx% "FreeRTOS D2XX Example/%2"
copy /y %cm_freertos% "FreeRTOS Example 1/%2"
copy /y %cm_freertos% "FreeRTOS Example 2/%2"
copy /y %cm_freertos% "FreeRTOS Example 3/%2"
copy /y %cm_freertos% "FreeRTOS Example 4/%2"
copy /y %cm_freertos_lwip% "FreeRTOS lwIP Example/%2"
copy /y %cm_basic% "GPIO DFU Example/%2"
copy /y %cm_basic% "GPIO Example 1/%2"
copy /y %cm_basic% "GPIO Example 2/%2"
copy /y %cm_basic% "GPIO Example 3/%2"
copy /y %cm_basic% "I2C Master Example 1/%2"
copy /y %cm_basic% "I2C Master Example 2/%2"
copy /y %cm_basic% "I2C Slave Example 1/%2"
copy /y %cm_basic% "I2S Master Example 1/%2"
copy /y %cm_basic% "I2S Master Example 2/%2"
copy /y %cm_basic% "PWM Example 1/%2"
copy /y %cm_basic% "PWM Example 2/%2"
copy /y %cm_basic% "PWM Example 3/%2"
copy /y %cm_basic% "RTC Example 1/%2"
copy /y %cm_basic% "RTC Example 2/%2"
copy /y %cm_basic% "RTC External Example 1/%2"
copy /y %cm_basic% "RTC External Example 2/%2"
copy /y %cm_fatfs% "SD Host Example 1/%2"
copy /y %cm_basic% "SPI Master Example 1/%2"
copy /y %cm_basic% "SPI Master Example 2/%2"
copy /y %cm_basic% "SPI Master Example 3/%2"
copy /y %cm_basic% "SPI Slave Example 1/%2"
copy /y %cm_basic% "Timer Example 1/%2"
copy /y %cm_basic% "Timer Example 2/%2"
copy /y %cm_basic% "Timer Example 3/%2"
copy /y %cm_basic% "UART 9Bit Mode Example/%2"
copy /y %cm_basic% "UART Example 1/%2"
copy /y %cm_basic% "UART Example 2/%2"
copy /y %cm_basic% "UART Example 3/%2"
copy /y %cm_basic% "UART Example 4/%2"
copy /y %cm_basic% "USBD Example BOMS to SDcard/%2"
copy /y %cm_basic% "USBD Example CDCACM/%2"
copy /y %cm_basic% "USBD Example Composite/%2"
copy /y %cm_basic% "USBD Example HID/%2"
copy /y %cm_basic% "USBD Example HID Bridge/%2"
copy /y %cm_basic% "USBH Example BOMS/%2"
copy /y %cm_basic% "USBH Example CDCACM/%2"
copy /y %cm_fatfs% "USBH Example File System/%2"
copy /y %cm_basic% "USBH Example FT232/%2"
copy /y %cm_basic% "USBH Example HID/%2"
copy /y %cm_basic% "USBH Example HID to UART/%2"
copy /y %cm_basic% "USBH Example Hub/%2"
copy /y %cm_basic% "Watchdog Example 1/%2"

rem Clean up temporary files.
del %cm_basic%
del %cm_fatfs%
del %cm_freertos%
del %cm_freertos_lwip%
del %cm_freertos_d2xx%
del %cm_d2xxdev%
del %cm_d2xxhost%

:eof
