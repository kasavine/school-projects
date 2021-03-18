#!/bin/bash

UUID=$(uuidgen)
MAIL="${UUID}@gmail.com"
echo "Creating new user with mail: ${MAIL}"
curl -X POST -i http://localhost:8080/users -d "firstname=Joey" -d "lastname=Tribbiani" -d "age=40" -d "password=111" -d "email=${MAIL}" || exit 1

echo "Testing sign in"
curl -X POST -i -c cookies.txt http://localhost:8080/sign_in -d "email=${MAIL}" -d "password=111" || exit 1

echo "Testing sign out"
curl -X DELETE -b cookies.txt http://localhost:8080/sign_out || exit 1

echo "Sign in and delete"
curl -X POST -i -c cookies.txt http://localhost:8080/sign_in -d "email=${MAIL}" -d "password=111" || exit 1
curl -X DELETE -b cookies.txt  http://localhost:8080/users || exit 1