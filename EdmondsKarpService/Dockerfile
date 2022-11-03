FROM gcc:latest

RUN apt-get update && apt-get install -y cmake libcpprest-dev libssl-dev

WORKDIR /src

EXPOSE 8080

COPY ./ /src/EdmondsKarpService

COPY ./Common /src/Common

RUN mkdir /src/build

WORKDIR /src/build

RUN cmake ../EdmondsKarpService

RUN make EdmondsKarpService

ENTRYPOINT ["./EdmondsKarpService"]
