#!/bin/bash

edited_text="$(sed "/cout/d;/\/\//d" main.cpp)"
echo "$edited_text" > sanitized.cpp
