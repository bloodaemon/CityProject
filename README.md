name: Pedro Peres

name: Richard Szeto

ECS 175: Computer Graphics
UC Davis, Spring 2013
Project 4 - 3D city scene

To compile use the following commands:
cmake .
make
./CityProject.x

The program should cover all the specifications asked in the assignment. In our program we have buildings, moving cars, parked cars, background, a sky box, mailboxes, billboards, street signs. 

Most buildings are randomly generated, where the height of buildings being increasingly higher as you get toward the center of the city. The textures of buildings are also mostly randomly generated. 

=============================================================

Commands to control the camera:

8 - changes the camera view. There are 5 different camera views. 4 of them are follows a car or is attached to a car. Only one allows user to control its movements (the first comera allows user to control its movements).

a - moves camera in the +x direction

d - moves camera in the -x direction

w - moves camera in the +z direction

s - moves camera in the -z direction

t - moves camera in the -y direction

g - moves camera in the +y direction

to rotate the camera use: 

o - rotates down
l - rotates up
k - rotates to the left 
u - rotests to the right 


