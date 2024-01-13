FROM node:alpine
# If there exist a directory called app, use it, otherwise create a new one
WORKDIR /app
COPY package*json /app
RUN npm install
COPY . /app
CMD node server.mjs

