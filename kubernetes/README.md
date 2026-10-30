# Kubernetes

Local Kubernetes on Linux with minikube + kubectl.

## install minikube

```sh
curl -LO https://github.com/kubernetes/minikube/releases/latest/download/minikube-linux-amd64
sudo install minikube-linux-amd64 /usr/local/bin/minikube
minikube version
```

## install kubectl

```sh
curl -LO "https://dl.k8s.io/release/$(curl -L -s https://dl.k8s.io/release/stable.txt)/bin/linux/amd64/kubectl"
sudo install kubectl /usr/local/bin/kubectl
kubectl version --client
```

> minikube also bundles its own copy: `minikube kubectl -- version`

## start cluster

```sh
minikube start --driver=docker
minikube status
```

## check cluster

```sh
kubectl get po -A
kubectl get nodes
kubectl cluster-info
```

## create service

```sh
kubectl create deployment hello-minikube --image=kicbase/echo-server:1.0
kubectl expose deployment hello-minikube --type=NodePort --port=8080
kubectl port-forward service/hello-minikube 7080:8080
```

open http://localhost:7080 , or let minikube pick a url:

```sh
minikube service hello-minikube --url
```

## everyday kubectl

```sh
kubectl get deploy,svc,po
kubectl describe pod <pod>
kubectl logs <pod> -f
kubectl exec -it <pod> -- sh
kubectl apply -f manifest.yaml
kubectl delete -f manifest.yaml
kubectl scale deployment hello-minikube --replicas=2
kubectl rollout status deployment/hello-minikube
kubectl get events --sort-by=.lastTimestamp
```

## manifest example

`hello-minikube.yaml`:

```yaml
apiVersion: apps/v1
kind: Deployment
metadata:
  name: hello-minikube
spec:
  replicas: 2
  selector:
    matchLabels:
      app: hello-minikube
  template:
    metadata:
      labels:
        app: hello-minikube
    spec:
      containers:
        - name: hello-minikube
          image: kicbase/echo-server:1.0
          ports:
            - containerPort: 8080
---
apiVersion: v1
kind: Service
metadata:
  name: hello-minikube
spec:
  type: NodePort
  selector:
    app: hello-minikube
  ports:
    - port: 8080
      targetPort: 8080
```

```sh
kubectl apply -f hello-minikube.yaml
```

## config & secrets

```sh
kubectl create configmap app-config --from-literal=APP_ENV=dev
kubectl create secret generic app-secret --from-literal=API_KEY=xxx
kubectl get cm,secret
```

## stop / delete cluster

```sh
minikube stop
minikube delete --all
```