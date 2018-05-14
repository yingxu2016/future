#!/bin/bash

echo "Testing I - memory limitation 100,000 bytes; key-value pair 1,000,000"
./test_unit.sh ./externalGroupBy 100000 1000000
echo "Testing II - memory limitation 10,000 bytes; key-value pair 1,000,000"
./test_unit.sh ./externalGroupBy 10000 1000000
echo "Testing III - memory limitation 1,000 bytes; key-value pair 1,000,000"
./test_unit.sh ./externalGroupBy 1000 1000000
