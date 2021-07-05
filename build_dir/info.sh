#!/bin/bash
#
# Copyright (c) 2016 Javier Sayago <admin@lonasdigital.com>
# Contact: javilonas@esp-desarrolladores.com
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#    http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

clear

version=0.3
user=`id -g -n`

echo 
echo "============================================================"
echo " Build System NCam Version $version by Javier Sayago (Javilonas). "
echo "============================================================"
echo 
echo "> ABOUT BUILD SYSTEM NCAM"
echo
echo "------------------------------------------------------------"
echo "  Tool to facilitate the construction of NCAM."
echo "  Designed for users clumsier, With this tool, "
echo "  you can build your own binary NCAM."
echo
echo "  The binary is generated in /home/$user/NCam/Distribution"
echo "  The logs is generated in /home/$user/NCam/build_dir/logs"
echo
echo "  Official Support   : https://www.lonasdigital.com"
echo "  Sources NCam       : https://github.com/javilonas/NCam"
echo "  Paypal donations   : https://www.paypal.me/Javilonas"
echo "------------------------------------------------------------"
echo

echo
echo "Press Enter to continue"
read enterKey

