import bgcc.*;

public final class Server
{
	public static void main(String[] args){

        Logger logger = new Logger("bgcc.cfg");
        Global.instance().setLogger(logger);

        ServiceManager serviceManager = new ServiceManager();

        MathImpl impl = new MathImpl();
        math.Math.Processor processor = new math.Math.Processor(impl);

        serviceManager.addService(processor);

        ThreadPool threadPool = new ThreadPool(10);

        logger.trace("bgcc", "create server");
        bgcc.Server server = new bgcc.Server(serviceManager, threadPool, 8503);

        logger.trace("bgcc", "before serve");
        server.serve();
	}
}
