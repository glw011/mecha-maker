#!/bin/bash

ENGINE_PATH="/home/Public/Linux_Unreal_Engine_5.7.1"
UAT="$ENGINE_PATH/Engine/Build/BatchFiles/RunUAT.sh"
SCRIPT_DIR="$(dirname "$(realpath "$0")")"
PROJECT="$SCRIPT_DIR/MechaMaker.uproject"
ARCHIVE_DIR="$SCRIPT_DIR/Packaged/Linux"

if [ ! -f "$UAT" ]; then
    echo "ERROR: RunUAT.sh not found at $UAT"
    echo "Check UE 5.7.1 installed at $ENGINE_PATH"
    exit 1
fi

if [ ! -f "$PROJECT" ]; then
    echo "ERROR: MechaMaker.uproject not at $PROJECT"
    exit 1
fi

echo "=== MechaMaker Linux Build ==="
echo "Engine : $ENGINE_PATH"
echo "Project: $PROJECT"
echo "Output : $ARCHIVE_DIR"
echo ""

"$UAT" BuildCookRun \
    -project="$PROJECT" \
    -noP4 \
    -platform=Linux \
    -clientconfig=Shipping \
    -cook \
    -allmaps \
    -build \
    -stage \
    -pak \
    -compressed \
    -archive \
    -archivedirectory="$ARCHIVE_DIR"

if [ $? -ne 0 ]; then
    echo ""
    echo "ERROR: Packaging failed... Logs in: $SCRIPT_DIR/Saved/Logs/"
    exit 1
fi

echo ""
echo "=== BUILD COMPLETED SUCCESSFULLY! Archived to: $ARCHIVE_DIR ==="
