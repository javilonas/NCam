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

export user=`id -g -n`
export ROOTFS_PATH=/home/$user/NCam
export DISTRI=$ROOTFS_PATH/Distribution
export NCAM_BIN=ncam*
export SCRIPT=clean_distri.sh
echo ""
echo ""
echo "=============================================="
echo "   START CLEAN DISTRI"
echo "=============================================="
echo ""
echo ""
echo " Remove binary..."
echo ""
sleep 0.8s
echo ""
cd $DISTRI/
rm -f $NCAM_BIN > /dev/null 2>&1
cd ..
chmod 755 $ROOTFS_PATH/build_dir/$SCRIPT > /dev/null 2>&1
sleep 0.8s
sync
echo ""
echo " Deleted binary"
echo ""
sleep 0.8s
echo ""
echo "=============================================="
echo "   END CLEAN DISTRI"
echo "=============================================="
echo ""
echo ""
sleep 0.8s
