lab8
====

##Prelab

![alt text](https://raw.githubusercontent.com/JeremyGruszka/lab8/master/gradesheet.PNG "gradesheet")

####Things I may need to know for the lab

Only the door you are trying to get functionality for will be open - all others will be closed. We can't expect our robot to know to skip openings!
 
If you get A Functionality, you get credit for Required and B Functionality. There is no need to complete the maze through all doors.
 
There are a variety of techniques that cadets have used in the past to solve the maze. Here are a few:
 •Use a wall-following algorithm (i.e., it tries to maintain a certain distance from the wall).
 •Use an empty-space detecting algorithm. If it gets too close to a wall, it steers away.
 
####Pseudocode

I'm going to have my robot crawl along the left wall and turn left once it hits sees a wall in front of it the first time.  I will then go straight forward to get required functionality.  To get B functionality, I'll make a right turn when my robot sees the first closed door in front of it.  To get A functionality, I'll have the robot make a right turn when it hits the far wall, and a left turn to go through the final door.  I don't see this being too hard to do, considering I have already gotten my robot to move and and the IR sensors to work.  Its just a matter of interfacing them together
