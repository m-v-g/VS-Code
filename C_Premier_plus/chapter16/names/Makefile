CC = gcc
CFLAGS = -Wall -Wextra

# Цель по умолчанию: создание исполняемого файла 'useheader'
all: useheader.exe

# Цель 'useheader.exe': линковка объектных файлов 'useheader.o' и 'names_st.o'
useheader.exe: useheader.o names_st.o
	$(CC) $(CFLAGS) -o useheader.exe useheader.o names_st.o

# Цель 'useheader.o': компиляция исходного файла 'useheader.c' в объектный файл 'useheader.o'
useheader.o: useheader.c names_st.h
	$(CC) $(CFLAGS) -c useheader.c

# Цель 'names_st.o': компиляция исходного файла 'names_st.c' в объектный файл 'names_st.o'
names_st.o: names_st.c names_st.h
	$(CC) $(CFLAGS) -c names_st.c

# Цель 'clean': удаление всех созданных объектных файлов и исполняемого файла
clean:
	del useheader.exe *.o
