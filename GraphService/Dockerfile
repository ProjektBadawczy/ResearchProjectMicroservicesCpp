FROM gcc:latest

RUN apt-get update && apt-get install -y cmake libcpprest-dev libssl-dev

WORKDIR /src

EXPOSE 8080

COPY ./ /src/GraphService

COPY ./Common /src/Common

RUN mkdir /src/build

COPY ./graphs/ /src/build/graphs

WORKDIR /src/build

RUN cmake ../GraphService

RUN make GraphService

ENTRYPOINT ["./GraphService"]
