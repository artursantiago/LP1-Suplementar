## How to use 👨🏻‍💻
- Clone this repository and enter it

- Now you can easily use Makefile to compile the project:
```
 $ make
 ```

After you compile the project, it will generate the compiled file with the name `supermercado` on the root path. So just initialize like this and will open a interactive mode.

```
$ ./supermercado
```

By default, your stock is located on the root path. You can change this in `supermercado.config`.

```
path = estoque.csv
```

The print formated is also defined in the file above.

```
default_format = [%c] %n - %p/%u
```

You can use the foolowing symbols to change for your informations:

- **%c** => Product Code
- **%n** => Product Name
- **%p** => Product Price
- **%u** => Unit of Measurement


<blockquote alt="[ignore]">
  <p>
    This project is only for study purposes. The brand, logo and name are non professional
  </p>
</blockquote>
