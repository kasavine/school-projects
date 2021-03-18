# my-users-app

#### POST on users
curl -X POST -i http://localhost:8080/users -d "firstname=Joey" -d "lastname=Tribbiani" -d "age=40" -d "password=111" -d "email=joey22@gmail.com"

#### GET on users
curl http://localhost:8080/users

#### POST on sign_in
curl -X POST -i -c cookies.txt http://localhost:8080/sign_in -d "email=joey22@gmail.com" -d "password=111"

#### GET on sign_in
curl -X GET -i -b cookies.txt http://localhost:8080/read -d "email=chandler@gmail.com" -d "password=111"

#### PUT on users
curl -X PUT -b cookies.txt  http://localhost:8080/users -d "password=12345"

#### DELETE on sign_out
curl -X DELETE -b cookies.txt  http://localhost:8080/sign_out

#### DELETE on users
curl -X DELETE -b cookies.txt  http://localhost:8080/users

#### KEYS
-vvv --> very very visual

-X --> By default, curl sends GET requests. To make it send POST requests, use the -X POST command line argument.

-d --> To add POST data to the request

-i --> includes the HTTP headers in the output

-c --> Save Cookies to a File

-b --> Load Cookies from a File

