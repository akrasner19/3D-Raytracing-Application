Put Your design decisions here. What modules you defined and how they
interact to solve the ray tracing problem.

I split up my code into 3 main modules

The first, vtray, contains the code that deals with inputs and files. 
It checks for any errors that are thrown by the functions it calls, 
as well as checking for syntax errors in the input lines.

The second module, geometry, does two main things.
It checks the file to make sure that it is valid. 
Then it generates objects that represent the environment that is going to be rendered.

The third module, raytracer, uses the environment in geometry to render the image.
It uses threads to do this. By default there is only one thread used.

The way that I do threading is each thread goes through each pixel and calculates the image value. 
The value is stored in a vector that is accessible to each thread.
To prevent overlap, each thread increments through the x-values of the pixel grid by the 
number of threads that exist. Each time it starts a thread it begins the index into the grid
at the location of the thread number.