from ida_bytes import get_byte, patch_byte
 
def range_xor(start_addr, end_addr, xor_num):
    for the_addr in range(start_addr, end_addr+1):
        the_byte = get_byte(the_addr)
        patch_byte(the_addr, the_byte ^ xor_num)
 
range_xor(0x00411894, 0x004118AF, 0x23)