all :svr user rela mess photo

user: 
	g++ -c -o user.o userManager.cpp
rela:
	g++ -c -o relaI.o RelationInfo.cpp
	g++ -c -o relaM.o RelationManager.cpp
mess:
	g++ -c -o mess.o MessageManager.cpp
photo:
	g++ -c -o photo.o PhotoManager.cpp
svr:
	g++ -o server_ssp *.o main.cpp Socket.cpp Config.cpp
clean:
	rm -f *.o
