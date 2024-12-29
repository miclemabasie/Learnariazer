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
`docker pull <imagename>:<tag>`

See the list of images in the system
`docker images`
This command shows the following information about the image
(REPOSITORY, TAG, IMAGE iD, CREATED, SIZE)

Running a container from an image -> See defination of a container above
`docker run <imagename>:<tag>`
`docker run -d <imagename><tag>` The `-d` flag here means to run in detached mood (release the shell and run on the background)

The above command starts up the container but produces no output with no output

To see the list of running images we can use the following command
`docker container ls`
OR
`docker ps`
`docker ps -a` The `a` flag here means, all the images should be displayed regarless of their status

To stop a container we use the following command
`docker stop <containerID>` Note that the container ID is displayed when we use the command `docker ps`

### EXPOSING PORTS

In the case of running a webserver such as NGINX on a docker container, we need a way to communicate with server software running inside the container, since NGINX is a webserver and runs on port 80 we can map a port on our local machine which when a requests is made through that port, the request is sent to the NGINX server

#### localhost:8080

#### Port 8080 on host maps to 80 in the NGINX container.

This configuration is obtained by adding `-p 8080:80` when running the container
So we get a command that looks like this `docker run -d -p 8080:80 nginx:latest`

The following command maps two different ports to the NGINX server
`docker run -d -p 3000:80 -p 8080:80 nginx:latest`

### Managing Containers

- `docker ps` Display running containers.
- `docker ps -a` Display all containers.
- `docker stop <containerID>` Stopping a container but not removing it.
- `docker start <containerID>` running a container that had been earlear stoped .
- `docker rm <containerID>` Removes containers that have been stopped .
- `docker ps -aq` Retuns the IDs of all the containers.
- `docker rm $(docker ps -aq)` This will remove all the containers that are not avaible (and not running).
  If we try to remove a running container using the above command we get an error, in this case if we do not mind proceding with the removal then we type:
- `docker rm -f <containerID`
  OR
- `docker rm -f $(docker ps -aq)` This command removes every container (Running or Stopped) status

### NAMING CONTAINERS

By default, random names are given to every container when you run them without specifying a name.
To specify a name during the running of a container, we do:
`docker run --name website -d -p 3000:80 -p 8080:80 nginx:latest`
So now we can run commands against this container using it's name
`docker stop website`

#### Using formats for output

`docker ps --format="check docker display format online and paste here."`

### DOCKER VOLUMES

Docker volumes are a mechanism that allows us to share data (files and or folders) between host and container and also between containers.

#### Mouting a volumbe from host to the container

`docker run --name website -v $(pwd):/usr/share/nginx/html:ro -d -p 8080:80 nginx`

##### Breaking down the command

- `docker run` This command simply starts up the container
- `--name website` This flag is used to give a custom name to the running command
- `-v $(pwd):/usr/share/nginx/html:ro ` This is to mount a volume in the container
  - `-v` This flag tells the docker that volum is to be mounted
  - `$(pwd)` This returns the current path of the system such as `/home/electron/Dev/recoverlearn/Learnariazer/docker` on the host machine which holds the folder to be loaded into the volum.
  - `:usr/share/nginx/html` This is to specify where on the container we want to mount the volum or store the contents
  - `:ro` This represents a read only volum
- `-d` Run the container in detatched mode
- `-p 8080:80` Map port 8080 from the host machine to port 80 on the container
- `nginx` The name of the container we wish to run.

With this configuration all the files in this folder specified in the volume will authomatically be present inside the container and all the files in the conatiner in the path specified as destination in the command will authomatically be present in the host machine aswell

To confirm this, we can go into the shell of the terminal itself and create new files and see how it works, to do so we use the following command

`docker exec -it website bash`

If this command works properly we are then given a shell, in which we can navigate to `usr/share/nginx/html`
using `cd /usr/share/nginx/html`

it should be noted that volumes created with the `ro` options will not allow the container to write any content to the volume, if we dont like this configuration then we can remove the `ro` before running the container which will make it look like this.
`docker run --name website -v $(pwd):/usr/share/nginx/html -d -p 8080:80 nginx`

### Sharing Volumes Between Containers

Docker provides us a need way of specifying which a volume to be loaded from another existing container during the run process of the container

`docker rum --name website-copy --volumes-from website -d -p 3000:80 nginx`

This command starts up a container with the volume from the another container called website.

## DOCKERFILE

A dockerfile allows us to create our own images by creating a file called `dockerfile`
This file simply contains a list of instructions on an image is to be created
After this is done we can run the images the same way we've been running those downloaded from docker hub such as nginx

#### consult the dockerfile reference for more information on this, see example below

#### File Structure of our website

- Website
  - images
  - css
  - js
  - index.html
  - dockerfile

When mounting a volume we are simple referencing some content inside our host machine to be used by the container, and this must be done everytime the container is to be started up.
To avoid this we can build our own custom image which has all the things it need to server out website propery and is completely on it's own on all the information we need, we do this copying the content from out machine into the container this is seen in the example below

Inside `website/dockerfile`

```
FROM nginx:latest
COPY . /usr/share/nginx/html/
```

After creating this file we need to build the image
`docker build --tag website:latest .`

### EXAMPLE OF DOCKFILES IN NODEJS AND EXPRESS CONFIGURATION

The following is a sample configuration for a node/express dockerfile which is is at it bear mininum.

```
FROM node:latest
# If there exist a directory called app, use it, otherwise create a new one
WORKDIR /app
COPY . /app
RUN npm install
CMD node server.mjs

```

We use the following command to build an image from the above configuration
`docker build -t user-api-service .` The dot at the end of the command indicates where the dockerfile is located with respect to our current location on the file system

The above command will create an image with the name 'user-api-service'

Running a container from this image
`docker run --name user-api -d -p 3000:3000 user-api-service:latests`
Now run `docker ps` to see the list of running images
You should see and image with name `user-api` listening on port 3000

### DOCKERIGNORE

There are usualy certain files we wish to ignore when building images with docker, these includes files such as project dependencies which will be installed when the project is started such as the `node_modules` folder in our case of node/express

To avoid this we create a new file in out project directory called `.dockerignore` it shoud have the following content (as an example)

```
node_modules
Dockerfile
.git
*.gulp.js
```

All the files specified inside the dockerignore file and the those on the project directory that match the wildcat property will be aswell excluded from the docker build

#### Using and Understanding how Caching works in Docker

In a simple docker configuration, whenever a change is made to our code, docker has to recompute every step that is after the COPY or ADD command which can be very time consuming this is where we take avantage of caching

This is achieved by rearanging the content in out dockerfile in a very logical set of layers, the following is a sample configuration that will be very effective and elimnate the need of reinstalling project dependencies every time we make change

```
FROM node:alpine
# If there exist a directory called app, use it, otherwise create a new one
WORKDIR /app
COPY package*json /app
RUN npm install
COPY . /app
CMD node server.mjs
```

In the above configuration notice how we first now copy the package\*.json which will include all the dependencies that needs to be installed, before we add the project, this because Docker works in layers when we build an image, it only changes all the content below the command that changed when we rebuild every image, in this scenario we are trying to put the `COPY . /app` statement below the `npm install` so that when the code changes, and we copy the code into the container again then docker would register a change at this stage and would not have to reinstall all dependencies.

### ALPINE

This are linux distribution of images which are quite small in size compared to the regular images
To obtain this distribution we simply specify alpine as the tag of the image, such as:
`docker pull node:lts-alpine` The available tags can be found on the node repo in the docker hub.
`docker pull nginx:alpine`
Read more about alpine [here](www.alpinelinux.org)

### Making custom images to use alpine versions

```
FROM node:alpine
# If there exist a directory called app, use it, otherwise create a new one
WORKDIR /app
COPY . /app
RUN npm install
CMD node server.mjs
```

Note that the code above pulls an alpine version of the node image as it's base image.

### TAGS AND VERSIONING

- Allows you to control image versions
- Avoid breaking changes, due to changes in software versions

`docker pull node:alpine` imagine this pulls version 8
`docker pull node:alpine` and this pulls version 12
This all could potentially lead to breaking your code base due to changes in software dependencies
This is where tags and version comes in to save the day, which gives us full control of the exact images we are working with
`docker pull node:12-alpine`

#### Adding tags to images when we build them

To add a tag to an image when it's been build we do the following
`docker build -t <image-name>:<tagname> <dockerfile>`
`-t` Allows you to specify a tag which does the same as `--tag` below.
or
`docker build -t <image-name>:<tagname> <dockerfile>`

#### EXamples of tagging

1. We buid the image
   `docker buid -t miclem-website:latest`
2. We create a new image with a tag base off the newly created build
   `docker tag miclem-website:latest miclem-website:1`
3. After making some changes to the website and we wish to release version two
   `docker buid -t miclem-website:latest`
   `docker tag miclem-website:latest miclem-website:2`

So this means we have 3 containers

- miclem-website:latest
- miclem-website:1
- miclem-website:2

Note that `:latest` always points to the the most recent version of the website just as `:2`

#### Dockerfile

```
FROM node:12.7.0-alpine
# If there exist a directory called app, use it, otherwise create a new one
WORKDIR /app
COPY . /app
RUN npm install
CMD node server.mjs
```

### DOCKER REGISTRY

This is a scalable server side application that stores and lets you distribute Docker images
Also used for CD/CI Pipeline
Run your applications

There are two types of docker registries Private and Public
Private Images are used when we want the images to only be seen and used by use the developers
Public Images are used when we don't mind if anybody sees and uses our image

#### Docker Registry providers include:

- [Docker Hub](www.dockerhub.com)
- [Quay](quay.io)
- Amazon ECR

Most commonly we use the docker hub since it provides us a free plan for pushing and pulling personal images

#### How to push images from our host to repo on docker hub

Assuming that we have created a docker repository called `website` which will be store with our username like this `miclemabase/website`
`docker push <username>/<name:tag>`

Example
To push this images we need to properly tag them as per the dockerhub conventions
`docker tag miclem-website:1 miclemabasie/website:1`
`docker tag miclem-website:2 miclemabasie/website:2`
`docker tag miclem-website:latest miclemabasie/website:latest`

Then we can push them as follows
`docker login` Command to login into dockerhub from the terminal.

`docker push miclemabasie/website:1`
`docker push miclemabasie/website:2`
`docker push miclemabasie/website:latest`

### How to pull own images from dockerhun

Remove Image if exists
`docker rmi miclemabasie/website:latest`
`docker rmi miclemabasie/website:1`
`docker rmi miclemabasie/website:2`

`docker pull miclemabasie/website` This woudl authomaticaly pull the latest version
`docker pull miclemcbasie/website:1` This pulls the version 1 of the image

### DOCKER INSPECT

The `docker ps` command simply gives us some basic information about a container, but sometimes we might want to investigate what is fully going on inside a container, to do this, we use the inspect command:
`docker inspect <containerID>`

This command produces output that looks like the following

```
[
    {
        "Id": "0826bffd07fe0d1abb766986cb1a6cd6601b5f48fe7b0cab8db82e1ffac363df",
        "Created": "2023-12-21T12:02:21.979793592Z",
        "Path": "/entrypoint",
        "Args": [
            "/start-flower"
        ],
        "State": {
            "Status": "exited",
            "Running": false,
            "Paused": false,
            "Restarting": false,
            "OOMKilled": false,
            "Dead": false,
            "Pid": 0,
            "ExitCode": 255,
            "Error": "",
            "StartedAt": "2023-12-21T12:02:23.052111626Z",
            "FinishedAt": "2023-12-26T13:49:41.122734758Z"
        },
        "Image": "sha256:4f248945a3c751af81c15542caa1a7f3d328a281751461da6ddeb8a14154fde9",
        "ResolvConfPath": "/var/lib/docker/containers/0826bffd07fe0d1abb766986cb1a6cd6601b5f48fe7b0cab8db82e1ffac363df/resolv.conf",
        "HostnamePath": "/var/lib/docker/containers/0826bffd07fe0d1abb766986cb1a6cd6601b5f48fe7b0cab8db82e1ffac363df/hostname",
        "HostsPath": "/var/lib/docker/containers/0826bffd07fe0d1abb766986cb1a6cd6601b5f48fe7b0cab8db82e1ffac363df/hosts",
        "LogPath": "/var/lib/docker/containers/0826bffd07fe0d1abb766986cb1a6cd6601b5f48fe7b0cab8db82e1ffac363df/0826bffd07fe0d1abb766986cb1a6cd6601b5f48fe7b0cab8db82e1ffac363df-json.log",
        "Name": "/django-real-estate_flower_1",
        "RestartCount": 0,
        "Driver": "overlay2",
        "Platform": "linux",
        "MountLabel": "",
        "ProcessLabel": "",
        "AppArmorProfile": "docker-default",
        "ExecIDs": null,
        "HostConfig": {
            "Binds": [
                "/home/electron/Dev/python/python2023/django-real-estate:/app:rw"
            ],
            "ContainerIDFile": "",
            "LogConfig": {
                "Type": "json-file",
                "Config": {}
            },
            "NetworkMode": "django-real-estate_estate-react-network",
            "PortBindings": {
                "5555/tcp": [
                    {
                        "HostIp": "",
                        "HostPort": "5557"
                    }
                ]
            },
            "RestartPolicy": {
                "Name": "",
                "MaximumRetryCount": 0
            },
            "AutoRemove": false,
            "VolumeDriver": "",
            "VolumesFrom": [],
            "ConsoleSize": [
                0,
                0
            ],
            "CapAdd": null,
            "CapDrop": null,
            "CgroupnsMode": "private",
            "Dns": [],
            "DnsOptions": [],
            "DnsSearch": [],
            "ExtraHosts": null,
            "GroupAdd": null,
            "IpcMode": "private",
            "Cgroup": "",
            "Links": null,
            "OomScoreAdj": 0,
            "PidMode": "",
            "Privileged": false,
            "PublishAllPorts": false,
            "ReadonlyRootfs": false,
            "SecurityOpt": null,
            "UTSMode": "",
            "UsernsMode": "",
            "ShmSize": 67108864,
            "Runtime": "runc",
            "Isolation": "",
            "CpuShares": 0,
            "Memory": 0,
            "NanoCpus": 0,
            "CgroupParent": "",
            "BlkioWeight": 0,
            "BlkioWeightDevice": null,
            "BlkioDeviceReadBps": null,
            "BlkioDeviceWriteBps": null,
            "BlkioDeviceReadIOps": null,
            "BlkioDeviceWriteIOps": null,
            "CpuPeriod": 0,
            "CpuQuota": 0,
            "CpuRealtimePeriod": 0,
            "CpuRealtimeRuntime": 0,
            "CpusetCpus": "",
            "CpusetMems": "",
            "Devices": null,
            "DeviceCgroupRules": null,
            "DeviceRequests": null,
            "MemoryReservation": 0,
            "MemorySwap": 0,
            "MemorySwappiness": null,
            "OomKillDisable": null,
            "PidsLimit": null,
            "Ulimits": null,
            "CpuCount": 0,
            "CpuPercent": 0,
            "IOMaximumIOps": 0,
            "IOMaximumBandwidth": 0,
            "MaskedPaths": [
                "/proc/asound",
                "/proc/acpi",
                "/proc/kcore",
                "/proc/keys",
                "/proc/latency_stats",
                "/proc/timer_list",
                "/proc/timer_stats",
                "/proc/sched_debug",
                "/proc/scsi",
                "/sys/firmware",
                "/sys/devices/virtual/powercap"
            ],
            "ReadonlyPaths": [
                "/proc/bus",
                "/proc/fs",
                "/proc/irq",
                "/proc/sys",
                "/proc/sysrq-trigger"
            ]
        },
        "GraphDriver": {
            "Data": {
                "LowerDir": "/var/lib/docker/overlay2/4a83b29830f742b2c60276e724f41069f8e2fcbc941edd18bbdd3ee9a60cf859-init/diff:/var/lib/docker/overlay2/0a8mrx23557rfqz5zvridhkh8/diff:/var/lib/docker/overlay2/jjaglfmvi0d99np4me894a47f/diff:/var/lib/docker/overlay2/fm9nzjrtybjvw14mlkri6a87r/diff:/var/lib/docker/overlay2/tsi7feoehbfcmb7y0jacyfkjk/diff:/var/lib/docker/overlay2/omk10zvdoqpvyab4y37uig5y8/diff:/var/lib/docker/overlay2/z8e1uis2ln6cpazi91my8w2hv/diff:/var/lib/docker/overlay2/t13edmacwka9yhyu6lf3g1w3k/diff:/var/lib/docker/overlay2/sg6b7qep6yes39tdamtrc5n83/diff:/var/lib/docker/overlay2/exw305fri5z1ej94rykpxn7bu/diff:/var/lib/docker/overlay2/ayeg4hwdfuvxdy2zilkykcsgg/diff:/var/lib/docker/overlay2/p9pnc00kzxizbisctej30c36u/diff:/var/lib/docker/overlay2/29uvq2p34tbg48hp9eecth4ur/diff:/var/lib/docker/overlay2/h8kg89ckjh93kobo44rhynnys/diff:/var/lib/docker/overlay2/kq5xensrqq3ydh83peod4gn51/diff:/var/lib/docker/overlay2/w0nm8w8h0lzoiab8kya2n3q43/diff:/var/lib/docker/overlay2/otk2bqv28n91xoyl9nm6xdnh7/diff:/var/lib/docker/overlay2/x1lrpjenmhbh31r6q1z1c4nsn/diff:/var/lib/docker/overlay2/ri0dv1m8h0xmcx8oinwv9mc2f/diff:/var/lib/docker/overlay2/qk9h21rmrcn9m374esf00mw7c/diff:/var/lib/docker/overlay2/mga47qdlds0f3eeivn2jigkuu/diff:/var/lib/docker/overlay2/f52dd118a70df77c3b9e68eca4a0ea3196aa352f18b05953e7b37b8157bf38e9/diff:/var/lib/docker/overlay2/6d0cd7339459edb7993cff1f44e4e6cbe2d70d54f1a21deea928a0077bcb2311/diff:/var/lib/docker/overlay2/07ec15929d849551f8427f2d7ff9862317013448354120017ad4a9bf15926442/diff:/var/lib/docker/overlay2/09ec5bd860213b34146e17a7b4f1522b565c16bc14c410ee3465d82d6add81b2/diff:/var/lib/docker/overlay2/c9983443e8801bf5ba426c8ee0d94c830afe16676935ae635eca40491cc8005b/diff",
                "MergedDir": "/var/lib/docker/overlay2/4a83b29830f742b2c60276e724f41069f8e2fcbc941edd18bbdd3ee9a60cf859/merged",
                "UpperDir": "/var/lib/docker/overlay2/4a83b29830f742b2c60276e724f41069f8e2fcbc941edd18bbdd3ee9a60cf859/diff",
                "WorkDir": "/var/lib/docker/overlay2/4a83b29830f742b2c60276e724f41069f8e2fcbc941edd18bbdd3ee9a60cf859/work"
            },
            "Name": "overlay2"
        },
        "Mounts": [
            {
                "Type": "bind",
                "Source": "/home/electron/Dev/python/python2023/django-real-estate",
                "Destination": "/app",
                "Mode": "rw",
                "RW": true,
                "Propagation": "rprivate"
            }
        ],
        "Config": {
            "Hostname": "0826bffd07fe",
            "Domainname": "",
            "User": "",
            "AttachStdin": false,
            "AttachStdout": false,
            "AttachStderr": false,
            "ExposedPorts": {
                "5555/tcp": {}
            },
            "Tty": false,
            "OpenStdin": false,
            "StdinOnce": false,
            "Env": [
                "SECRET_KEY=kldsjfaasdfasdfasdfasdfasdfasdlkfhasdfadwflkhasd",
                "DEBUG=True",
                "ALLOWED_HOSTS=localhost 0.0.0.0 [::1]",
                "POSTGRES_ENGINE=django.db.backends.postgresql",
                "POSTGRES_DB=realestate_learn",
                "POSTGRES_USER=miclem",
                "POSTGRES_PASSWORD=1234",
                "POSTGRES_HOST=postgres-db",
                "POSTGRES_PORT=5432",
                "SIGNING_KEY=ask5w2r3wer2342342Q%%^&$%^$%^$sdlkfa>fadslkjfazxczcxm,bn",
                "EMAIL_HOST=sandbox.smtp.mailtrap.io",
                "EMAIL_HOST_USER=1e7b0e3598e335",
                "EMAIL_HOST_PASSWORD=cd9793cf22a678",
                "EMAIL_PORT=2525",
                "DOMAIN=localhost:8000",
                "MAIL_GUN_API_KEY=bafd9c614656e284148d034a7394d15c-07f37fca-81238a50",
                "CELERY_BROKER_URL=redis://redis:6379/0",
                "CELERY_BACKEND=redis://redis:6379/0",
                "PATH=/usr/local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin",
                "LANG=C.UTF-8",
                "GPG_KEY=A035C8C19219BA821ECEA86B64E628F8D684696D",
                "PYTHON_VERSION=3.10.0",
                "PYTHON_PIP_VERSION=21.2.4",
                "PYTHON_SETUPTOOLS_VERSION=57.5.0",
                "PYTHON_GET_PIP_URL=https://github.com/pypa/get-pip/raw/3cb8888cc2869620f57d5d2da64da38f516078c7/public/get-pip.py",
                "PYTHON_GET_PIP_SHA256=c518250e91a70d7b20cceb15272209a4ded2a0c263ae5776f129e0d9b5674309",
                "APP_HOME=/app",
                "PYTHONDONTWRITEBYTECODE=1",
                "PYTHONUNBUFFERED=1"
            ],
            "Cmd": [
                "/start-flower"
            ],
            "Image": "django-real-estate_flower",
            "Volumes": {
                "/app": {}
            },
            "WorkingDir": "/app",
            "Entrypoint": [
                "/entrypoint"
            ],
            "OnBuild": null,
            "Labels": {
                "com.docker.compose.config-hash": "91964e2ca0584ba1c8f2309d93a04aed4b7b1dffe315c4d592ae52add8c62eca",
                "com.docker.compose.container-number": "1",
                "com.docker.compose.oneoff": "False",
                "com.docker.compose.project": "django-real-estate",
                "com.docker.compose.project.config_files": "docker-compose.yml",
                "com.docker.compose.project.working_dir": "/home/electron/Dev/python/python2023/django-real-estate",
                "com.docker.compose.service": "flower",
                "com.docker.compose.version": "1.29.2",
                "description": "Development Image for Real Estate Project",
                "maintainer": "api.amikom@mail.com",
                "youtube": "https://www.youtube.com/channel/UCDwKxHq1n9l9PZd6eJ9B5Dw"
            }
        },
        "NetworkSettings": {
            "Bridge": "",
            "SandboxID": "ce8e1a151bd90a0cc205a2abf97b7822bdde3c68432818740d10aaaf3e0c56d1",
            "HairpinMode": false,
            "LinkLocalIPv6Address": "",
            "LinkLocalIPv6PrefixLen": 0,
            "Ports": {
                "5555/tcp": [
                    {
                        "HostIp": "0.0.0.0",
                        "HostPort": "5557"
                    },
                    {
                        "HostIp": "::",
                        "HostPort": "5557"
                    }
                ]
            },
            "SandboxKey": "/var/run/docker/netns/ce8e1a151bd9",
            "SecondaryIPAddresses": null,
            "SecondaryIPv6Addresses": null,
            "EndpointID": "",
            "Gateway": "",
            "GlobalIPv6Address": "",
            "GlobalIPv6PrefixLen": 0,
            "IPAddress": "",
            "IPPrefixLen": 0,
            "IPv6Gateway": "",
            "MacAddress": "",
            "Networks": {
                "django-real-estate_estate-react-network": {
                    "IPAMConfig": null,
                    "Links": null,
                    "Aliases": [
                        "flower",
                        "0826bffd07fe"
                    ],
                    "NetworkID": "e20a18588e58199cd8fcfed0c5bbd755eb88a54bc8ec430849fbd95bafe4678e",
                    "EndpointID": "f6c5e90b34164d3b4a83d7855fd177a7b6bcf9ade3f74032aae567f22afd5398",
                    "Gateway": "192.168.48.1",
                    "IPAddress": "192.168.48.7",
                    "IPPrefixLen": 20,
                    "IPv6Gateway": "",
                    "GlobalIPv6Address": "",
                    "GlobalIPv6PrefixLen": 0,
                    "MacAddress": "02:42:c0:a8:30:07",
                    "DriverOpts": null
                }
            }
        }
    }
]
```

### DOCKER LOGS

In the case where we need to actualy see what's going on inside a container this is where logs come ininerID>
``` something similar should appear below
This indicates all the information the application has been spitting out during runtime in the case of a server.

```
PostgreSQL is up - continuing...
################## /app
Error: No nodes replied within time constraint
Celery worker is unavailable - sleeping
################## /app
->  celery@6368ec8ab3a8: OK
        pong

1 node online.
Celery worker is up - continuing...
################## /app
2023-12-21 12:02:33,178 flower.command WARNING  You have incorrectly specified the following celery arguments after flower command: ['--broker']. Please specify them after celery command instead following this template: celery [celery args] flower [flower args].
2023-12-21 13:02:34,595 flower.command INFO     Visit me at http://0.0.0.0:5555
2023-12-21 13:02:34,601 flower.command INFO     Broker: redis://redis:6379/0
2023-12-21 13:02:34,606 flower.command INFO     Registered tasks:
['celery.accumulate',
 'celery.backend_cleanup',
 'celery.chain',
 'celery.chord',
 'celery.chord_unlock',
 'celery.chunks',
 'celery.group',
 'celery.map',
 'celery.starmap',
 'djcelery_email_send_multiple']
2023-12-21 13:02:34,615 kombu.mixins INFO     Connected to redis://redis:6379/0
```

`docker logs -f <containerID>` This is used to follow the logs as see them as there appear

### DOCKER EXEC

Since a container is like a running machine, sometimes we might want to get into the container and actualy see what is inside or even install software and perform custom configuration, we use the `exec` command to achieve this

`docker exec -it <containerID> bash`
OR
`docker exec -it <container-name> bash`

Understanding the options

- `-i` This runs the command in iteractive mode
- `-t` Provides a tty shell for typing commands.
- `bash` This represents where the bash shell in found inside the container

Note: To find out where exactly the bash terminal is found, we can run the command `docker inspect <containerID>` and then search for the "CMD" settings, this would look something like this

```
"Cmd": [
   "/bin/sh",
   "-C",
   "node index.js"
]
```

Which in the case above the command to type would now look like this `docker exec -it <conatinerId> /bin/sh`
