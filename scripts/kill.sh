#!/bin/bash

pid=$(pgrep main.x)
eval kill $pid
