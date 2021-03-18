require 'sqlite3'

class User 
    @@db = nil
    def initialize()
        if (@@db == nil)
            @@db = SQLite3::Database.new "my_user_app.db" 
            @@db.execute <<-SQL
                CREATE TABLE IF NOT EXISTS users (
                user_id INTEGER PRIMARY KEY, 
                firstname varchar(50), 
                lastname varchar(50), 
                age INTEGER, 
                password varchar(50), 
                email varchar(50));
                SQL
        end
    end
        
    def get_user_id(email)
        @@db.execute("SELECT user_id from users WHERE email = '#{email}'") do |row|
            return row[0];
        end
    end

    def create(user_info)
        @@db.execute("INSERT INTO users (firstname, lastname, age, password, email) VALUES (?, ?, ?, ?, ?)", user_info)
        return get_user_id(user_info[4])
    end

    def get(user_id)
        @@db.execute("SELECT * FROM users WHERE user_id = #{user_id}") do |row|
            p row
        end
    end

    def find(user_email, user_password)
        return @@db.execute("SELECT * from users WHERE email = '#{user_email}' AND password = '#{user_password}'")
    end
    
    def all
        users_array = @@db.execute "SELECT * FROM users"
    end

    def all_without_password
        users_array = @@db.execute "SELECT email FROM users"
        return users_array
    end

    def update(user_id, attribute, value)
        # @@db.results_as_hash = true
        @@db.execute("UPDATE users SET #{attribute}=? WHERE user_id=?", value, user_id)
    end

    def destroy(user_id)
        @@db.execute("DELETE FROM users WHERE user_id = #{user_id}")
    end
end

# user = User.new()
# p user.create(["Chandler","Bing",30,"111","chandlerdfgh@gmail.com"])
# user.create(["Phoebe","Buffay",30,"222","phoebe@gmail.com"])
# user.create(["Monica","Geller",25,"333","monica@gmail.com"])
# user.create(["Rachel","Green",21,"444","rachel@gmail.com"])
# user.create(["Joey","Tribbiani",27,"555","joey@gmail.com"])
# user.create(["Ross","Geller:",19,"666","ross@gmail.com"])


# user.all()
# user.get(3)
# user.update(3,"lastname","BBBBBBBBB")
# user.destroy(1)