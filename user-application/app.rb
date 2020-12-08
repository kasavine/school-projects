require "rubygems"
require "sinatra"
require_relative "./run"

# set :port, 8080

# POST on /users. Receiving firstname, lastname, age, password and email. 
# It will create a user and store in your database.

# post '/users' do
#     .. create something ..
# end


# GET on /users. 
# This action will return all users (without their passwords).

get '/' do
    User.all.join
end


# POST on /sign_in. Receiving email and password. 
# It will add a session containing the user_id in order to be logged in.

# post '/sign_in' do
#     .. create something ..
# end


# PUT on /users. This action require a user to be logged in. 
# It will receive a new password and will update it. It returns the hash of the user.

# put '/users' do
#     .. replace something ..
# end


# DELETE on /sign_out. This action require a user to be logged in. 
# It will sign_out the current user.

# delete '/sign_out' do
#     .. annihilate something ..
# end


# DELETE on /users. This action require a user to be logged in. 
# It will sign_out the current user and it will destroy the current user.

# delete '/users' do
#     .. annihilate something ..
# end
