This project is a multithreaded, 3D rendering engine written in C++. It reads .json files and uses ray tracing to export an image of the scene.

My code is organized into 3 main modules

The first, vtray, contains the code that deals with inputs and files. 
It checks for any errors that are thrown by the functions it calls, 
as well as checking for syntax errors in the input lines.

The second module, geometry, handles two main tasks.
It checks the file to make sure that it is valid. 
Then it generates objects that represent the environment that is going to be rendered.

The third module, raytracer, uses the environment in geometry to render the image.
It accomplishes the rendering using threads. By default there is only one thread used.

Given the files `scene1.json` and `scene2.json`, the application will output the below images

![alt text](https://github.com/akrasner19/3D-Raytracing-Application/tests/scene1.png "Output for scene1.json")

![alt text](https://github.com/akrasner19/3D-Raytracing-Application/tests/scene2.png "Output for scene2.json")

The rendering process is accomplished by having threads go through each pixel and calculates the image value. These RGB values are determined based on the vector from the light source(s), any blocked light source(s), the surface color, and the lambert coefficient of the surface. The value is stored in a vector that is accessible to each thread. To prevent overlap, each thread increments through the x-values of the pixel grid by the number of threads that exist. Each time it starts a thread it begins the index into the grid at the location of the thread number.

This can also be accomplished with mutex and locking on each pixel with concurrent threads in a thread pool, but due to time constraints I did not originally implement it in that way. Additionally, later in testing, I found the relative efficiencies of the two methods to be very similar. 

The goal of this project was to gain mastery of concurrent programming and creating a large scale project from complete scratch.

ECE 3574 Project 3
