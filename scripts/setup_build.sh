#!/bin/bash

source /grid/fermiapp/products/uboone/setup_uboone.sh

export ART_SEAQUEST_QUAL=e9:nu:s30 # workbook 0.91 
source /e906/app/users/yuhw/art-seaquest/art-seaquest/ups/setup_for_development -p $ART_SEAQUEST_QUAL
