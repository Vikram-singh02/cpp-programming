#!/bin/bash

# Test script for Basic Linked List implementation
# This script performs automated testing of the linked list program

echo "=== Starting Automated Tests for Basic Linked List ==="

# Check if executable exists
if [ ! -f "./linkedlist" ]; then
    echo "❌ ERROR: Executable 'linkedlist' not found!"
    exit 1
fi

echo "✅ Executable found"

# Test 1: Check if program starts and exits properly
echo "🧪 Test 1: Program startup and exit"
echo "7" | timeout 10s ./linkedlist > /dev/null 2>&1
if [ $? -eq 0 ]; then
    echo "✅ Test 1 PASSED: Program starts and exits properly"
else
    echo "❌ Test 1 FAILED: Program doesn't start/exit properly"
    exit 1
fi

# Test 2: Test basic functionality with automated input
echo "🧪 Test 2: Basic functionality test"
TEST_OUTPUT=$(echo -e "1\n10\n2\n20\n4\n7" | timeout 10s ./linkedlist 2>/dev/null)
if echo "$TEST_OUTPUT" | grep -q "10.*20.*NULL"; then
    echo "✅ Test 2 PASSED: Basic insert and display operations work"
else
    echo "❌ Test 2 FAILED: Basic operations don't work as expected"
    echo "Output was: $TEST_OUTPUT"
    exit 1
fi

# Test 3: Test search functionality
echo "🧪 Test 3: Search functionality test"
TEST_OUTPUT=$(echo -e "1\n15\n5\n15\n7" | timeout 10s ./linkedlist 2>/dev/null)
if echo "$TEST_OUTPUT" | grep -q "found in the list"; then
    echo "✅ Test 3 PASSED: Search functionality works"
else
    echo "❌ Test 3 FAILED: Search functionality doesn't work"
    exit 1
fi

# Test 4: Test size functionality
echo "🧪 Test 4: Size functionality test"
TEST_OUTPUT=$(echo -e "1\n5\n1\n3\n6\n7" | timeout 10s ./linkedlist 2>/dev/null)
if echo "$TEST_OUTPUT" | grep -q "2 nodes"; then
    echo "✅ Test 4 PASSED: Size functionality works"
else
    echo "❌ Test 4 FAILED: Size functionality doesn't work correctly"
    exit 1
fi

# Test 5: Test invalid input handling
echo "🧪 Test 5: Invalid input handling"
TEST_OUTPUT=$(echo -e "abc\n99\n7" | timeout 10s ./linkedlist 2>/dev/null)
if echo "$TEST_OUTPUT" | grep -q "Invalid"; then
    echo "✅ Test 5 PASSED: Invalid input handling works"
else
    echo "❌ Test 5 FAILED: Invalid input not handled properly"
    exit 1
fi

echo ""
echo "🎉 All tests passed successfully!"
echo "✅ Build verification completed"
echo "=== Test Summary ==="
echo "✅ Program compilation: PASSED"
echo "✅ Basic functionality: PASSED"
echo "✅ Search feature: PASSED"
echo "✅ Size feature: PASSED"
echo "✅ Error handling: PASSED"
echo ""
