require "sinatra"
require_relative "my_user_model"
set :port, 8080
set :bind, '0.0.0.0'
enable :sessions

get '/' do
    @user = User.new()
    erb :index
end 

# POST on /users. Receiving firstname, lastname, age, password and email. 
# It will create a user and store in your database.

post '/users' do
    @user = User.new()
    new_user = [params[:firstname], params[:lastname], params[:age].to_i, params[:password], params[:email]]
    return @user.create(new_user)
end

# GET on /users. --> This action will return all users (without their passwords).

get '/users' do
    @user = User.new()
    @user.all_without_password.to_s
end

# POST on /sign_in. Receiving email and password. 
# It will add a session containing the user_id in order to be logged in.

post '/sign_in' do
    @user = User.new()
    email = params[:email]
    password = params[:password]
    user = @user.find(email, password)
    if user.length == 0
        return 'Wrong email or password'
    else
        session[:logged_user] = user[0][0]
        return 'OK'
    end
end

# PUT on /users. This action require a user to be logged in. 
# It will receive a new password and will update it. 
# It returns the hash of the user.

put '/users' do
    @user = User.new()
    user = session[:logged_user]
    if user != nil
        @user.update(session[:logged_user], "password", params[:password])
        return user.to_s
    else
        'FORBIDDEN'
    end
end

# DELETE on /sign_out. This action require a user to be logged in. 
# It will sign_out the current user.

delete '/sign_out' do
    @user = User.new()
    if session[:logged_user] != nil
        session.delete(:logged_user)
        'OK'
    else
        'You have to be signed in before sign out.'
    end
end

# DELETE on /users. This action require a user to be logged in. 
# It will sign_out the current user and it will destroy the current user.

delete '/users' do
    @user = User.new()
    user = session[:logged_user] 
    if user != nil
        session.delete(:logged_user)
        @user.destroy(user)
        'User was logged out and deleted'
    else
        'You have to be "signed in" to perform this action'
    end
end
