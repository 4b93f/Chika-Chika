service mysql start

#EDIT FOR ALL ACCESS
chown -R www-data /var/www/*
chmod -R 755 /var/www/*

# Create our folder
mkdir /var/www/mywebsite 
#touch /var/www/mywebsite/index.php
#echo "<?php phpinfo(); ?>" >> /var/www/mywebsite/index.php

#Create SSL
mkdir /etc/nginx/ssl
openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes -out /etc/nginx/ssl/mywebsite.pem -keyout /etc/nginx/ssl/mywebsite.key -subj "/C=FR/ST=Bruxelles/L=Becentral/O=19 School/OU=chly-huc/CN=mywebsite"

# Config NGINX

mv ./root/nginx-conf /etc/nginx/sites-available/mywebsite
ln -s /etc/nginx/sites-available/mywebsite /etc/nginx/sites-enabled/mywebsite
rm -rf /etc/nginx/sites-enabled/default

# CONFIG MYSQL AND USER
echo "CREATE DATABASE wordpress;" | mysql -u root --skip-password
echo "CREATE USER 'pd'@'locahost' IDENTIFIER BY 'QWERTY';" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'pd'@'localhost' IDENTIFIED BY 'QWERTY' WITH GRANT OPTION;" | mysql -u root --skip-password
# echo "update mysql.user set plugin='mysql_native_password' where user='charli';" | mysql -u root --skip-password
# echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password


# INSTALL PHPMYADMIN
mkdir /var/www/mywebsite/phpmyadmin
wget https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.tar.gz
tar -xvf phpMyAdmin-4.9.0.1-all-languages.tar.gz --strip-components 1 -C /var/www/mywebsite/phpmyadmin
mv ./root/config.inc.php /var/www/mywebsite/phpmyadmin/config.inc.php


# INSTALL WORDPRESS
tar -xvf ./root/wordpress-5.4.tar.gz
mv wordpress /var/www/mywebsite
mv ./root/wp-config.php /var/www/mywebsite/wordpress

# START SERVER
service php7.3-fpm start
service nginx restart
bash