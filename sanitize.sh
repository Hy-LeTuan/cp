#!/bin/bash

edited_text="$(sed "/cout/d;/\/\//d" main.cpp)"
echo "$edited_text" > sanitized.cpp
emptied="$(sed '/^$/d' sanitized.cpp)"
echo "$emptied" > sanitized.cpp

