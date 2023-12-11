 #!/bin/bash

# First we create object files for c files with the (-c -fPIC )
# Then we create the dynamic library liball.so
# Then we remove all the object files
gcc -Wall -Wextra -Werror -pedamtic  -c -fPIC *.c
gcc -shared -o liball.so *.o
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
