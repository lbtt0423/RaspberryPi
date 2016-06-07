all : run_dht11 run_buzzer run_colourthree run_ds18b20 run_shock run_ps2

objects = dht11.o buzzer.o colourthree.o ds18b20.o shock.o ps2.o   

run_dht11 : $(objects) test_dht11.o 
	gcc -o run_dht11 $(objects) test_dht11.o -lwiringPi -Wall
run_buzzer : $(objects) test_buzzer.o 
	gcc -o run_buzzer $(objects) test_buzzer.o -lwiringPi -Wall	
run_colourthree : $(objects) test_colourthree.o 
	gcc -o run_colourthree $(objects) test_colourthree.o -lwiringPi -Wall	
run_ds18b20 : $(objects) test_ds18b20.o 
	gcc -o run_ds18b20 $(objects) test_ds18b20.o -lwiringPi -Wall	
run_shock : $(objects) test_shock.o 
	gcc -o run_shock $(objects) test_shock.o -lwiringPi -Wall	
run_ps2 : $(objects) test_ps2.o 
	gcc -o run_ps2 $(objects) test_ps2.o -lwiringPi -Wall	


	
dht11.o : dht11.c 
	gcc -c dht11.c -lwiringPi -Wall
buzzer.o : buzzer.c 
	gcc -c buzzer.c -lwiringPi -Wall
colourthree.o : colourthree.c 
	gcc -c colourthree.c -lwiringPi -Wall
ds18b20.o : ds18b20.c 
	gcc -c ds18b20.c -lwiringPi -Wall
shock.o : shock.c 
	gcc -c shock.c -lwiringPi -Wall
ps2.o : ps2.c 
	gcc -c ps2.c -lwiringPi -Wall


	

test_dht11.o : test_dht11.c
	gcc -c test_dht11.c -lwiringPi -Wall
test_buzzer.o : test_buzzer.c
	gcc -c test_buzzer.c -lwiringPi -Wall
test_colourthree.o : test_colourthree.c
	gcc -c test_colourthree.c -lwiringPi -Wall
test_ds18b20.o : test_ds18b20.c
	gcc -c test_ds18b20.c -lwiringPi -Wall
test_shock.o : test_shock.c
	gcc -c test_shock.c -lwiringPi -Wall
test_ps2.o : test_ps2.c
	gcc -c test_ps2.c -lwiringPi -Wall


	
clean : 
	rm -f  run_dht11 run_buzzer run_colourthree run_ds18b20  run_shock run_ps2 $(objects)*.o
