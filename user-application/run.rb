require "sqlite3"

class User 

    @@connection = nil

    def initialize()
        if (@@connection == nil)
            # p "Im here"
            @@connection = SQLite3::Database.new "my_user_app.db" 
            @@connection.execute <<-SQL
                CREATE TABLE IF NOT EXISTS users (
                user_id INTEGER PRIMARY KEY, 
                firstname varchar(50), 
                lastname varchar(50), 
                age INT, 
                password varchar(50), 
                email varchar(50));
                SQL
        end
    end
        
    def create(user_info)
        @@connection.execute("INSERT INTO users (firstname, lastname, age, password, email) VALUES (?, ?, ?, ?, ?)", user_info)
    end

    def get(user_id)
        @@connection.execute("SELECT * FROM users WHERE user_id = #{user_id}") do |row|
            p row
        end
    end

    def all
        # @@connection.results_as_hash = true
        users_array = @@connection.execute "SELECT * FROM users"

        users_array.each do |row|
            p row
        end
    end

    def update(user_id, attribute, value)
        # @@connection.results_as_hash = true
        @@connection.execute("UPDATE users SET #{attribute}=? WHERE user_id=?", value, user_id)
    end

    def destroy(user_id)
        @@connection.execute("DELETE FROM users WHERE user_id = #{user_id}")
    end
end

# user = User.new()
# user.create(["Ivanna","Sak",30,"kljlkjlkl","kjkljlkjl"])
# user.create(["Slava","Kov",30,"aaaaa","aaaaaaa"])
# user.create(["Yana","Ale",25,"bbbbbbbb","bbbbbbbbbb"])
# user.create(["Vasyl","Pet",38,"ccccccccccccc","cccccccccccc"])
# user.create(["Mykola","Den",10,"ddddddd","dddd"])

# user.all()
# user.get(3)
# user.update(3,"lastname","BBBBBBBBB")
# user.destroy(1)