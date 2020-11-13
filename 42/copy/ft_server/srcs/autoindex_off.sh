rm /etc/nginx/sites-available/mywebsite
touch /etc/nginx/sites-available/mywebsite

echo "server {
	listen 80;
	listen [::]:80;
	server_name mywebsite;
	return 301 https://$host$request_uri;
}

server{

	listen 443 ssl ;
	listen [::]:443 ssl ;
	
	server_name mywebsite;
	
	ssl_certificate /etc/nginx/ssl/mywebsite.pem;
	ssl_certificate_key /etc/nginx/ssl/mywebsite.key;

	root /var/www/mywebsite;
	index index.html index.htm index.nginx-debian.html index.php;

	location / {
		autoindex off;
	}

	location ~ \.php$ {
		include snippets/fastcgi-php.conf;
		fastcgi_pass unix:/var/run/php/php7.3-fpm.sock;
	}
}" >> /etc/nginx/sites-available/mywebsite

service nginx restart