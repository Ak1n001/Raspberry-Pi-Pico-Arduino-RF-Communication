from machine import Pin
import time

# Set up GPIO7 as output
rf_pin = Pin(7, Pin.OUT)

def send_bit(bit):
    if bit == 1:
        rf_pin.value(1)
        time.sleep_us(500)
        rf_pin.value(0)
        time.sleep_us(200)
    else:
        rf_pin.value(1)
        time.sleep_us(200)
        rf_pin.value(0)
        time.sleep_us(500)

def send_byte(byte):
    for i in range(8):
        send_bit((byte >> (7 - i)) & 1)
    rf_pin.value(0)
    time.sleep_ms(2)  # sync gap

def send_message(message):
    for char in message + "\n":  # Add newline as end marker
        send_byte(ord(char))
    time.sleep(1)

while True:
    for i in range(1000000):
        send_message("Hello from Raspberry Pi")