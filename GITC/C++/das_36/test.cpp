    /*
    if ((pars & 0b00000011) != 0b00000011)
    {   //stugenq rasshireniner@ chist grats en te che
        cout << "Вы указали неверное расширение для целевого и/или конечного файла" << endl;
        cout << "Укажите пожалуйста файлы с расширением  .txt " << endl;
        return;
    }
    else if (!((((pars & 0b11000000) == 0b11000000) || ((pars & 0b00001000) == 0b00001000)) && (((pars & 0b00110000) == 0b00110000) || ((pars & 0b00000100) == 0b00000100))))
    {   //stugenq te kodirovkeq@ chisht en grac te che
        cout << "Вы указали неверное тип кодировки для целевого и/или конечного файла" << endl;
        cout << "Укажите пожалуйста типи кодировки  utf8 и/или utf16 и/или utf16be и/или utf16be" << endl;
        return;
    }
    else if ((pars & 0b00001100) == 0b00001100)
    {   //ete grace utf8-ic utf8 
        cout << "Бессмысленно конвертировать с utf8 на utf8 можно попросту переименовать файл" << endl;
        return;
    }
    
    else if ((pars & 0b01010000) == 0b01010000)
    {   //ete grace utf16be-ic utf16be
        #ifdef debug
            bitset8 = (pars & 0b01010000);
            cout << "Pars: " << bitset8 << endl;
        #endif
        cout << "Бессмысленно конвертировать с utf16be на utf16be можно попросту переименовать файл" << endl;
        return;
    }
    
    else if ((pars & 0b10100000) == 0b10100000)
    {   //ete grace utf16le-ic utf16le
        cout << "Бессмысленно конвертировать с utf16le на utf16le можно попросту переименовать файл" << endl;
        return;
    }
    
    else if ((pars & 0b11110000) == 0b11110000)
    {   //ete grace utf16-ic utf16 uremn swop enenq karevor ch fayl@ be te le
        read();
        if (((myVector.at(0) == 0xff) && (myVector.at(1) == 0xfe)) || ((myVector.at(0) == 0xfe) && (myVector.at(1) == 0xff)))
        {   //bayc skzbic stugenq te ed fayl@ vabshe utf16 e gone
            swop();
            return;
        }
        else
        {
            cout << "Кодировка файла не соответствует utf16" << endl;
            return;
        }
    }
    */
    else if ((pars & 0b01110000) == 0b01110000)
    {   //ete nshvac e utf16be -ic utf16
        read();
        if ((myVector.at(0) == 0xff) && (myVector.at(1) == 0xfe))
        {   //bayc skzbic stugenq te ed fayl@ vabshe utf16be e gone
            swop();
            return;
        }
        else
        {
            cout << "Кодировка файла не соответствует utf16be" << endl;
            return;
        }
    }
    else if ((pars & 0b10110000) == 0b10110000)
    {   //ete nshvac e utf16le -ic utf16
        read();
        if ((myVector.at(0) == 0xfe) && (myVector.at(1) == 0xff))
        {   //bayc skzbic stugenq te ed fayl@ vabshe utf16be e gone
            swop();
            return;
        }
        else
        {
            cout << "Кодировка файла не соответствует utf16le" << endl;
            return;
        }
    }
    else if ((pars & 0b01100000) == 0b01100000)
    {   //ete nshvac e utf16be -ic utf16le
        read();
        if ((myVector.at(0) == 0xff) && (myVector.at(1) == 0xfe))
        {   //bayc skzbic stugenq te ed fayl@ vabshe utf16be e gone
            swop();
            return;
        }
        else
        {
            cout << "Кодировка файла не соответствует utf16be" << endl;
            return;
        }
    }
    else if ((pars & 0b10010000) == 0b10010000)
    {   //ete nshvac e utf16le -ic utf16be
        read();
        if ((myVector.at(0) == 0xfe) && (myVector.at(1) == 0xff))
        {   //bayc skzbic stugenq te ed fayl@ vabshe utf16le e gone
            swop();
            return;
        }
        else
        {
            cout << "Кодировка файла не соответствует utf16le" << endl;
            return;
        }
    }
    /*
    else if ((pars & 0b11000100) == 0b11000100)
    {   //ete nshvac e utf16 -ic utf8
        read();
        if ((myVector.at(0) == 0xff) && (myVector.at(1) == 0xfe))
        {   //stugenq te ed fayl@ utf16be e
            utf16be_utf8();
            return;
        }
        else if ((myVector.at(0) == 0xfe) && (myVector.at(1) == 0xff))
        {   //stugenq te ed fayl@ utf16le e
            utf16le_utf8();
            return;
        }
        else
        {
            cout << "Кодировка файла не соответствует utf16" << endl;
            return;
        }
    }
    
    else if ((pars & 0b01000100) == 0b01000100)
    {   //ete nshvac e utf16be -ic utf8
        read();
        if ((myVector.at(0) == 0xff) && (myVector.at(1) == 0xfe))
        {   //stugenq te ed fayl@ utf16be e
            utf16be_utf8();
            return;
        }
        {
            cout << "Кодировка файла не соответствует utf16be" << endl;
            return;
        }
    }
    
    else if ((pars & 0b10000100) == 0b10000100)
    {   //ete nshvac e utf16le -ic utf8
        read();
        if ((myVector.at(0) == 0xfe) && (myVector.at(1) == 0xff))
        {   //stugenq te ed fayl@ utf16le e
            utf16le_utf8();
            return;
        }
        {
            cout << "Кодировка файла не соответствует utf16le" << endl;
            return;
        }
    }
    
    else if (((pars & 0b00011000) == 0b00011000) || ((pars & 0b00111000) == 0b00111000))
    {   //ete nshvac e utf8 -ic utf16 kam utf16be
        if ((myVector.at(0) == 0xfe) || (myVector.at(0) == 0xff))
        {   //stugenq te ed fayl@ karox e arden utf16 e
            utf8_utf16be();
            return;
        }
    }
    else if ((pars & 0b00101000) == 0b00101000)
    {   //ete nshvac e utf8 -ic utf16le
        if ((myVector.at(0) == 0xfe) || (myVector.at(0) == 0xff))
        {   //stugenq te ed fayl@ karox e arden utf16 e
            utf8_utf16le();
            return;
        }
    }
    else
    {
        cout << "Что то пошло не так !!!!!!!!!!!!!!!!" << endl;
        
    }
    */