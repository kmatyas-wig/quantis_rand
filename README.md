
# Table of Contents

1.  [Dependencies](#org73113ee)
2.  [Setup](#org37e7fbe)
    1.  [Locally](#orgca04a5b)
3.  [Use](#org50b3655)
4.  [Limitations, TODOs:](#orgcbe37d9)
5.  [License:](#orgcc54283)
6.  [Acknowledgments](#org45308bd)

This is the description of `quantis_rand`, a Python module for the
Quantis USB Legacy quantum random generator.

This package is a quick solution to use [Quantis USB Legacy quantum
random generator](https://www.idquantique.com/random-number-generation/products/quantis-random-number-generator/) in my projects. It is a simple interface to the
software libraries available for the device, enabling the call of the
functions of the supplied API from Python.

It might be useful for others, but it is written to meet limited
requirements of certain research projects. No warranty, use at your
own risk.


<a id="org73113ee"></a>

# Dependencies

The package has only been tested on an Ubuntu 18.04.6 LTS system.

It needs the libraries and includes from Quantis, which was kindly
provided by IdQuantique upon request in a file named
`QuantisRNG-20.2.3-Linux-amd64.tar.bz2`. This package had 3
subdirectories:

-   **lib64:** copy its contents to `/usr/local/bin`
-   **include:** copy its contents to `/usr/local/include`
-   **bin:** it is the supplied GUI application, not needed for this package.

The packages `libusb-1.0-0-dev` and `libusb-1.0-0` are also needed;
install these with `apt`.

Having completed these steps, the package can be installed.


<a id="org37e7fbe"></a>

# Setup


<a id="orgca04a5b"></a>

## Locally

    ./setup.py build
    ./setup.py install


<a id="org50b3655"></a>

# Use

We assume that a single random generator is plugged in to the USB port
of the computer and it has been set up properly. (Permissions are set,
etc.; if the supplied GUI works then it is probably the case.)

After importing the package:

    import quantis_rand

the following functions can be used:

-   `quantis_rand.drandom`
-   `quantis_rand.random`
-   `quantis_rand.scaled_double`
-   `quantis_rand.scaled_int`
-   `quantis_rand.randint`
-   `quantis_rand.randshort`
-   `quantis_rand.scaled_float`
-   `quantis_rand.scaled_short`

Most of them come from the device's official API (the present package
just makes API calls and translates between C++ an Python). Their
names are also self-explanatory. 
Help is available for each command in the standard way, e.g.

    help(quantis_rand.scaled_float)


<a id="orgcbe37d9"></a>

# Limitations, TODOs:

The library works for a single USB device of the given kind. Could be
extended to support various USB configs and other devices that can be
used with the same package. It could be tested on more platforms.


<a id="orgcc54283"></a>

# License:

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.


<a id="org45308bd"></a>

# Acknowledgments

This package has been developed as a part of a project financed by the
National Research, Development, and Innovation Office of Hungary under
project number K124351 and K133882, including the purchase of the
random generator device.

