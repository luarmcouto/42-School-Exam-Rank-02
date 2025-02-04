unsigned char reverse_bits(unsigned char octet)
{
    int i = 8;
    unsigned char res = 0;

    while (i > 0)
    {
        res = (res << 1) | (octet & 1);  // Desloca res para a esquerda e adiciona o bit menos significativo de octet
        octet = octet >> 1;  // Desloca octet para a direita para pegar o próximo bit
        i--;
    }
    return (res);
}

