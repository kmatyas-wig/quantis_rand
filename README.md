<div id="table-of-contents">
<h2>Table of Contents</h2>
<div id="text-table-of-contents">
<ul>
<li><a href="#sec-1">1. Dependencies</a></li>
<li><a href="#sec-2">2. Setup</a>
<ul>
<li><a href="#sec-2-1">2.1. Locally</a></li>
<li><a href="#sec-2-2">2.2. pip</a></li>
</ul>
</li>
<li><a href="#sec-3">3. Use</a></li>
<li><a href="#sec-4">4. Limitations, TODOs:</a></li>
<li><a href="#sec-5">5. License:</a></li>
<li><a href="#sec-6">6. Acknowledgments</a></li>
</ul>
</div>
</div>

This is the description of `quantis_random`, a Python module for the
Quantis USB Legacy quantum random generator.

This package is a quick solution to use <https://www.idquantique.com/random-number-generation/products/quantis-random-number-generator/>
in my projects. It is a simple interface to the software libraries
available for the device, enabling the call of the functions of the
supplied API from Python.

It might be useful for others, but it is written to meet limited
requirements of certain research projects. No warranty, use at your
own risk.

# Dependencies<a id="sec-1" name="sec-1"></a>

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

# Setup<a id="sec-2" name="sec-2"></a>

## Locally<a id="sec-2-1" name="sec-2-1"></a>

    ./setup.py build
    ./setup.py install

## pip<a id="sec-2-2" name="sec-2-2"></a>

tba

# Use<a id="sec-3" name="sec-3"></a>

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

# Limitations, TODOs:<a id="sec-4" name="sec-4"></a>

The library works for a single USB device of the given kind. Could be
extended to support various USB configs and other devices that can be
used with the same package. It could be tested on more platforms.

# License:<a id="sec-5" name="sec-5"></a>

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

# Acknowledgments<a id="sec-6" name="sec-6"></a>

This package has been developed as a part of a project financed by the
National Research, Development, and Innovation Office of Hungary under
project number K124351 and K133882, including the purchase of the
random generator device.
