-- MySQL dump 10.13  Distrib 5.5.46, for debian-linux-gnu (x86_64)
--
-- Host: 0.0.0.0    Database: pset7
-- ------------------------------------------------------
-- Server version	5.5.46-0ubuntu0.14.04.2

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `history`
--

DROP TABLE IF EXISTS `history`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `history` (
  `ID` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `user_id` int(10) unsigned NOT NULL,
  `transaction_type` varchar(255) NOT NULL,
  `symbol` varchar(255) NOT NULL,
  `shares` int(10) NOT NULL,
  `price` decimal(65,4) unsigned NOT NULL DEFAULT '0.0000',
  `transaction_cost` decimal(65,4) NOT NULL DEFAULT '0.0000',
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=48 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `history`
--

LOCK TABLES `history` WRITE;
/*!40000 ALTER TABLE `history` DISABLE KEYS */;
INSERT INTO `history` VALUES (1,9,'SELL','YHOO',-1,36.1700,36.1700),(2,9,'SELL','YHOO',-1,36.1700,36.1700),(3,9,'SELL','YHOO',-1,36.1700,36.1700),(4,9,'SELL','YHOO',-4,36.1700,144.6800),(5,9,'SELL','YHOO',-1,36.1700,36.1700),(6,9,'BUY','MSFT',1,54.4600,-54.4600),(7,9,'BUY','IBM',10,148.2500,-1482.5000),(8,9,'BUY','MSFT',10,54.4600,-544.6000),(9,9,'SELL','MSFT',-1,54.4600,54.4600),(10,24,'BUY','MSFT',10,54.4600,-544.6000),(11,24,'BUY','MSFT',1,54.4600,-54.4600),(12,24,'BUY','MSFT',1,54.4600,-54.4600),(13,24,'BUY','IBM',1,148.2500,-148.2500),(14,24,'BUY','C',1,40.2700,-40.2700),(15,24,'SELL','MSFT',-1,54.4600,54.4600),(16,24,'SELL','C',-1,40.2700,40.2700),(17,24,'BUY','MSFT',1,54.4600,-54.4600),(18,24,'BUY','C',1,40.2700,-40.2700),(19,24,'BUY','C',1,40.2700,-40.2700),(20,24,'BUY','C',1,40.2700,-40.2700),(21,24,'SELL','C',-1,40.2700,40.2700),(22,24,'BUY','JP',1,9.9000,-9.9000),(23,24,'BUY','JP',1,9.9000,-9.9000),(24,24,'BUY','M',1,40.6200,-40.6200),(25,24,'BUY','M',1,40.6200,-40.6200),(26,24,'BUY','IBM',1,148.2500,-148.2500),(27,24,'BUY','C',1,40.2700,-40.2700),(28,24,'BUY','M',1,40.6200,-40.6200),(29,24,'SELL','C',-1,40.2700,40.2700),(30,24,'BUY','IBM',10,148.2500,-1482.5000),(31,24,'SELL','M',-1,40.6200,40.6200),(32,24,'SELL','IBM',-1,148.2500,148.2500),(33,24,'SELL','IBM',-1,148.2500,148.2500),(34,24,'SELL','IBM',-1,148.2500,148.2500),(35,28,'BUY','MSFT',10,54.4600,-544.6000),(36,30,'BUY','FORD',5,1.3072,-6.5360),(37,30,'BUY','T',10,38.5900,-385.9000),(38,30,'BUY','T',10,38.5900,-385.9000),(39,30,'BUY','T',10,38.5900,-385.9000),(40,31,'BUY','MSFT',10,54.9200,-549.2000),(41,31,'SELL','MSFT',-1,54.9200,54.9200),(42,32,'BUY','FF',10,10.3700,-103.7000),(43,33,'BUY','MSFT',50,54.9600,-2748.0000),(44,33,'SELL','MSFT',-1,54.8600,54.8600),(45,33,'SELL','MSFT',-1,54.9000,54.9000),(46,33,'BUY','GOOG',1,742.9275,-742.9275),(47,33,'BUY','GOOG',1,742.6100,-742.6100);
/*!40000 ALTER TABLE `history` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `portfolios`
--

DROP TABLE IF EXISTS `portfolios`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `portfolios` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `user_id` int(10) unsigned NOT NULL,
  `symbol` varchar(255) NOT NULL,
  `shares` int(10) unsigned NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `user_id` (`user_id`,`symbol`),
  UNIQUE KEY `user_id_2` (`user_id`,`symbol`)
) ENGINE=InnoDB AUTO_INCREMENT=27 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `portfolios`
--

LOCK TABLES `portfolios` WRITE;
/*!40000 ALTER TABLE `portfolios` DISABLE KEYS */;
INSERT INTO `portfolios` VALUES (1,1,'YHOO',10),(3,2,'YHOO',10),(4,4,'YHOO',10),(5,5,'YHOO',10),(6,6,'YHOO',10),(7,7,'YHOO',10),(8,8,'YHOO',10),(9,9,'YHOO',49),(10,10,'YHOO',10),(11,11,'YHOO',10),(12,9,'MSFT',99),(13,24,'MSFT',0),(14,24,'IBM',9),(15,24,'C',0),(19,24,'M',0),(20,28,'MSFT',10),(21,30,'FORD',5),(22,30,'T',30),(23,31,'MSFT',9),(24,32,'FF',10),(25,33,'MSFT',48),(26,33,'GOOG',2);
/*!40000 ALTER TABLE `portfolios` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `users` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `cash` decimal(65,4) unsigned NOT NULL DEFAULT '0.0000',
  `username` varchar(255) NOT NULL,
  `hash` varchar(255) NOT NULL,
  `email` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=InnoDB AUTO_INCREMENT=36 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users`
--

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` VALUES (1,10000.0000,'andi','$2y$10$c.e4DK7pVyLT.stmHxgAleWq4yViMmkwKz3x8XCo4b/u3r8g5OTnS',NULL),(2,10000.0000,'caesar','$2y$10$0p2dlmu6HnhzEMf9UaUIfuaQP7tFVDMxgFcVs0irhGqhOxt6hJFaa',NULL),(3,10000.0000,'eli','$2y$10$COO6EnTVrCPCEddZyWeEJeH9qPCwPkCS0jJpusNiru.XpRN6Jf7HW',NULL),(4,10000.0000,'hdan','$2y$10$o9a4ZoHqVkVHSno6j.k34.wC.qzgeQTBHiwa3rpnLq7j2PlPJHo1G',NULL),(5,10000.0000,'jason','$2y$10$ci2zwcWLJmSSqyhCnHKUF.AjoysFMvlIb1w4zfmCS7/WaOrmBnLNe',NULL),(6,10000.0000,'john','$2y$10$dy.LVhWgoxIQHAgfCStWietGdJCPjnNrxKNRs5twGcMrQvAPPIxSy',NULL),(7,10000.0000,'levatich','$2y$10$fBfk7L/QFiplffZdo6etM.096pt4Oyz2imLSp5s8HUAykdLXaz6MK',NULL),(8,10000.0000,'rob','$2y$10$3pRWcBbGdAdzdDiVVybKSeFq6C50g80zyPRAxcsh2t5UnwAkG.I.2',NULL),(9,1833.2900,'skroob','$2y$10$395b7wODm.o2N7W5UZSXXuXwrC0OtFB17w4VjPnCIn/nvv9e4XUQK',NULL),(10,10000.0000,'zamyla','$2y$10$UOaRF0LGOaeHG4oaEkfO4O7vfI34B1W23WqHr9zCpXL68hfQsS3/e',NULL),(22,10000.0000,'test','$2y$10$IZ9o/HfeI0bU/tjt79KQ0OWas243Zqz89Wee6ETxIr1GPLaCmkF.W',NULL),(24,7776.1900,'test2','$2y$10$IVGRhKGpA6HI1DzoRbMcbeodCHC/l.k/.bKN90eICVksF3HVc1cVu',NULL),(25,10000.0000,'test3','$2y$10$LEJ5dHVdNjFCceqeHgKbG.YsevS2b7MBWghdDn8GO3PTqLmwckEMu',NULL),(26,10000.0000,'test4','$2y$10$21psKlCM1jazc9yFXvuMq.741v2ujfL0nqtCFGDgdcJTPnJp6Ijby',NULL),(27,10000.0000,'test5','$2y$10$tgauZW7Mx.YlGBlP.2XfZ.vKEFGdPns8PO17fkTxiTZ5f6DT/e4.i',NULL),(28,9455.4000,'test6','$2y$10$fCb2Fs5Vq.mEwcbs3.0Fj.yI9YVk9rHe2nOJfW0rMV3GvSYAyqvJ2',NULL),(29,10000.0000,'test7','$2y$10$nM21Q8iqLA9yMAaZo8483eIJXwwPGjExAJy3FYwAsLyx0KhO1nO3e',NULL),(30,8835.7640,'robu','$2y$10$6Fm0REVffn/oeHlxJlGIH.AWm4pGwtPcugOxW5rFt5i3zNVSMjpk6',NULL),(31,9505.7200,'test10','$2y$10$3RYLR4P783kfLsWJU59GOOdtbqZ4kk0DwdvN0awaUV7eOIQ13rIdS',NULL),(32,9896.3000,'test11','$2y$10$7kBael1tkWUXI3xoM3jgd.ra1H9EK7Sl.4rt363c1diUK8q4wA4k2',NULL),(33,5876.2225,'test99','$2y$10$IUkszIZJdMvE6wQcFpvy0O1iEqHSs2Itmw8NLqFj8R9DL0COPg4se',NULL),(34,10000.0000,'rob44','$2y$10$RIeOYNcvJZx4f.DOVg.UiOC9VmOoMsi8L/UgAnvCSjiPhf1xX0FFO','runderwood5@gmail.com'),(35,10000.0000,'test77','$2y$10$J9Hf/VtvijPMYz4hnivhE.8YzXZLh6KPfVuPn1WPsP70nT9JeLcTa','runderwood5+test77@gmail.com');
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2016-04-08 14:40:10
