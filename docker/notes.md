### BENEFITS

- Run container in seconds instead of minutes
- Less resources results in less disk space
- Uses less memory
- Does not need full OS
- Easy Deployment
- Easy Testing

### DOCKER IMAGE
- An Image is a template for creating an environment of your choice
- It is also a snapshot of a particular image
- Has everything needed to run the application
- OS, Software, App Code ...

### CONTAINER
- A container is simply a running instance of an image

### COMMANDS
Pull and image from docker hub repository
 ```docker pull <imagename>:<tag>```

See the list of images in the system
```docker images```
This command shows the following information about the image
(REPOSITORY, TAG, IMAGE iD, CREATED, SIZE)

Running a container from an image -> See defination of a container above
```docker run <imagename>:<tag>``` 
```docker run -d <imagename><tag>``` The ```-d``` flag here means to run in detached mood (release the shell and run on the background)

The above command starts up the container but produces no output with no output


To see the list of running images we can use the following command
```docker container ls```
OR
```docker ps```
```docker ps -a``` The  ```a``` flag here means, all the images should be displayed regarless of their status


To stop a container we use the following command
```docker stop <containerID>``` Note that the container ID is displayed when we use the command ```docker ps```

### EXPOSING PORTS
In the case of running a webserver such as NGINX on a docker container, we need a way to communicate with server software running inside the container, since NGINX is a webserver and runs on port 80 we can map a port on our local machine which when a requests is made through that port, the request is sent to the NGINX server

#### localhost:8080 
#### Port 8080 on host maps to 80 in the NGINX container.

This configuration is obtained by adding  ```-p 8080:80``` when running the container 
So we get a command that looks like this ```docker run -d -p 8080:80 nginx:latest```

The following command maps port two different ports to the NGINX server
```docker run -d -p 3000:80 -p 8080:80 nginx:latest``` 

### Managing Containers
- ```docker ps``` Display running containers.
- ```docker ps -a``` Display all containers.
- ```docker stop <containerID>``` Stopping a container but not removing it.
- ```docker start <containerID>``` running a container that had been earlear stoped .
- ```docker rm <containerID>``` Removes containers that have been stopped .
- ```docker ps -aq``` Retuns the IDs of all the containers.
- ```docker rm $(docker ps -aq)``` This will remove all the containers that are not avaible (and not running).
If we try to remove a running container using the above command we get an error, in this case if we do not mind proceding with the removal then we type:
- ```docker rm -f <containerID```
OR
- ```docker rm -f $(docker ps -aq)``` This command removes every container (Running or Stopped) status

### NAMING CONTAINERS
By default, random names are given to every container when you run them without specifying a name.
To specify a name during the running of a container, we do:
```docker run --name website -d -p 3000:80 -p 8080:80 nginx:latest```
So now we can run commands against this container using it's name
```docker stop website```

#### Using formats for output
```docker ps --format="check docker display format online and paste here."```


### DOCKER VOLUMES
Docker volumes are a mechanism that allows us to share data (files and or folders) between host and container and also between containers.

#### Mouting a volumbe from host to the container
```docker run --name website -v $(pwd):/usr/share/nginx/html:ro -d -p 8080:80 nginx```

##### Breaking down the command 
- ```docker run``` This command simply starts up the container
- ```--name website``` This flag is used to give a custom name to the running command
- ```-v $(pwd):/usr/share/nginx/html:ro ``` This is to mount a volume in the container
  - ```-v``` This flag tells the docker that  volum is to be mounted
  - ```$(pwd)``` This returns the current path of the system such as ```/home/electron/Dev/recoverlearn/Learnariazer/docker``` on the host machine which holds the folder to be loaded into the volum.
  - ```:usr/share/nginx/html``` This is to specify where on the container we want to mount the volum or store the contents
  - ```:ro``` This represents a read only volum
- ```-d``` Run the container in detatched mode
- ```-p 8080:80``` Map port 8080 from the host machine to port 80 on the container
- ```nginx``` The name of the container we wish to run.

With this configuration all the files in this folder specified in the volume will authomatically be present inside the container and all the files in the conatiner in the path specified as destination in the command will authomatically be present in the host machine aswell

To confirm this, we can go into the shell of the terminal itself and create new files and see how it works, to do so we use the following command

```docker exec -it website bash```

If this command works properly we are then given a shell, in which we can navigate to ```usr/share/nginx/html```
using ```cd /usr/share/nginx/html```

it should be noted that volumes created with the ```ro``` options will not allow the container to write any content to the volume, if we dont like this configuration then we can remove the ```ro``` before running the container which will make it look like this.
```docker run --name website -v $(pwd):/usr/share/nginx/html -d -p 8080:80 nginx```

### Sharing Volumes Between Containers
Docker provides us a need way of specifying which a volume to be loaded from another existing container during the run process of the container

```docker rum --name website-copy --volumes-from website -d -p 3000:80 nginx```

This command starts up a container with the volume from the another container called website.


## DOCKERFILE
A dockerfile allows us to create our own images by creating a file called ```dockerfile```
This file simply contains a list of instructions on an image is to be created
After this is done we can run the images the same way we've been running those downloaded from docker hub such as nginx

#### consult the dockerfile reference for more information on this, see example below

#### File Structure of our website
- Website
  - index.html
  - dockerfile