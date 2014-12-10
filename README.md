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

##Labwork

This lab was not only much easier than I thought it would be, but it was fun as well.  I started off by using my B functionality code from lab 7 as my base code, then combined my movement code from lab 6 into that code.  While this did not get the robot through the maze, it did work in the sense that my robot moved when the different IR sensors picked up walls.  

####Required functionality

I did this the hard way unfortunately.  I coded my robot in such a way that would detect walls and move away from them, otherwise known as an empty space detector.  This ended up with me crashing my robot into the walls at high speeds multiple times.  I'm pretty sure I may have had some minor heart attacks during this stage of the lab.  To fix this, I essentially just did a guess and check with the sensor values until the robot got through the required functionality door.  Captain Trimble watched my robot do this and signed off on my grade sheet.

####A functionality

I decided at this point to switch to an easier method of getting the robot through the maze.  I coded my robot so that it would stay within a certain distance of the left wall, otherwise known as a wall follower.  I modified my code to turn based on its proximity to the left wall, and the code actually worked the first time I wrote it.  The only problem was that the robot liked to spend a long time in the corners.  However, my robot got through the maze in about a minute and a half, and Captain Trimble once again watched my robot do this and signed off on my grade sheet.  I'm pretty sure this is the first time this semester I have gotten A functionality, so I was very excited when my robot got through the entire maze without touching a wall.

####Wiring

![alt text](https://raw.githubusercontent.com/JeremyGruszka/lab7/master/lab7_8robot.jpg "robot")

####Documentation

None
