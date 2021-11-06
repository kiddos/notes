### Tools

  - SRA tools [https://ftp-trace.ncbi.nlm.nih.gov/sra/sdk/2.11.3/sratoolkit.2.11.3-ubuntu64.tar.gz](https://ftp-trace.ncbi.nlm.nih.gov/sra/sdk/2.11.3/sratoolkit.2.11.3-ubuntu64.tar.gz)

  - TrimGalore [https://github.com/FelixKrueger/TrimGalore](https://github.com/FelixKrueger/TrimGalore)

  - bwa [https://github.com/lh3/bwa](https://github.com/lh3/bwa)

  - STAR [https://github.com/alexdobin/STAR](https://github.com/alexdobin/STAR)
  - samtools
    * [http://www.htslib.org/download/](http://www.htslib.org/download/)
    * [https://github.com/samtools/samtools](https://github.com/samtools/samtools)

  - Genome Browser [https://software.broadinstitute.org/software/igv/download](https://software.broadinstitute.org/software/igv/download)

  - HTSeq

    ```shell
    pip3 install --user HTSeq
    ```

### Processing

0. configure SRA tool with vdb-config

```shell
./sratoolkit.2.11.3-ubuntu64/bin/vdb-config
```

1. convert SRA to fastq

```shell
./sratoolkit.2.11.3-ubuntu64/bin/fastq-dump --stdout SRR16220071 > SRR16220071.fq
```

2. Cut Adaptor and Quality trimming

```shell
./TrimGalore-0.6.6/trim_galore SRR16220071.fq > SRR16220071_trimmed.fq
```

3. Mapping


- create FASTA index

```shell
./bwa index Saccharomyces_cerevisiae.R64-1-1.dna.toplevel.fa
```

this will generate the following

```shell
Saccharomyces_cerevisiae.R64-1-1.dna.toplevel.fa.amb
Saccharomyces_cerevisiae.R64-1-1.dna.toplevel.fa.ann
Saccharomyces_cerevisiae.R64-1-1.dna.toplevel.fa.bwt
Saccharomyces_cerevisiae.R64-1-1.dna.toplevel.fa.fai
Saccharomyces_cerevisiae.R64-1-1.dna.toplevel.fa.pac
Saccharomyces_cerevisiae.R64-1-1.dna.toplevel.fa.sa
```

- mapping

  * output SAM file

  ```shell
  /bwa mem Saccharomyces_cerevisiae.R64-1-1.dna.toplevel.fa SRR16220071_trimmed.fq > alignment.sam
  ```

  * output BAM file

  ```shell
  ./bwa/bwa mem -t 8 data/NGS/Saccharomyces_cerevisiae.R64-1-1.dna.toplevel.fa SRR16220071_trimmed.fq | ./samtools-1.14/samtools sort -o alignment_trimmed.bam
  ```

4. Generate index for alignment

  ```shell
  ./samtools-1.14/samtools index ./alignment_trimmed.bam
  ```

5. Genome Browser

  - load reference FASTA

  - load alignment BAM

6. Compute Gene Quantification

```shell
htseq-count ./alignment_trimmed.bam data/NGS/Saccharomyces_cerevisiae.R64-1-1.84.gtf > quanti.txt
```

