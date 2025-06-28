* install minikube

```sh
curl -LO https://github.com/kubernetes/minikube/releases/latest/download/minikube-linux-amd64
```

* start cluster with minikube

```sh
minikube start --driver=docker
```

* install kubectl

```sh
curl -LO "https://dl.k8s.io/release/$(curl -L -s https://dl.k8s.io/release/stable.txt)/bin/linux/amd64/kubectl"
```

```sh
kubectl version --client
```

* get pods

```sh
kubectl get po -A
```

* create service

```sh
kubectl create deployment hello-minikube --image=kicbase/echo-server:1.0
kubectl expose deployment hello-minikube --type=NodePort --port=8080
kubectl port-forward service/hello-minikube 7080:8080
```

```sh
minikube stop
minikube delete --all
```
