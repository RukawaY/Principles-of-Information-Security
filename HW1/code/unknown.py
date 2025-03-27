cipher_text = "MAL TIRRUEZF CR MAL RKZYIOL EX MAL OIY UAE RICF “MAL ACWALRM DYEUPLFWL CR ME DYEU MAIM UL IZL RKZZEKYFLF GH OHRMLZH”"

key_dict = {
    'M': 'T',
    'A': 'H',
    'L': 'E',
    'I': 'A',
    'E': 'O',
    'U': 'W',
    'Z': 'R',
    'X': 'F',
    'R': 'S',
    'C': 'I',
    'F': 'D',
    'T': 'P',
    'W': 'G',
    'K': 'U',
    'Y': 'N',
    'O': 'M',
    'D': 'K',
    'P': 'L',
    'H': 'Y'
}

plain_text = ""
for char in cipher_text:
    if char in key_dict.keys():
        plain_text += key_dict[char]
    else:
        plain_text += char

print(plain_text)