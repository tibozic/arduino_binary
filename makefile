##
# Arduino makefile
#
# @file
# @version 0.1

file = binary.ino

compile: ${file}
	arduino-cli compile --fqbn arduino:avr:uno ${file}

upload: ${file} compile
	arduino-cli upload -p /dev/ttyUSB0 --fqbn arduino:avr:uno ${file}

# end
